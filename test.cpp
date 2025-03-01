#include <cstdio>
#include <random>
#include <cmath>

typedef struct{
  double m;double g;
} arg;
enum Name{P,Q,Nums};
void step(double* x,double* y,arg c){
  y[P]=c.m*c.g;
  y[Q]=x[P]/c.m;
}
void xadd(double* x,double* k,double* y,double times){
  for(int i=0;i<Nums;i++)
    y[i]=x[i]+k[i]*times;
}
int main(){
  arg c={1,9.8};
  double x[2],k[4][2],tmp[2],rate[4]={1./6.,1./3.,1./3.,1./6.},DT;
  std::random_device st;std::mt19937 eng(st());
  std::uniform_real_distribution<> gen(0,1);
  for(double t=0;t<=10;t+=DT){
    printf("%lf,%lf,%lf\n",t,x[Q],x[P]);
    step(x, k[0], c);
    DT=-std::log(gen(eng))/(k[0][0]+k[0][1]);
    xadd(x, k[0], tmp, DT/2.0);
    step(tmp, k[1], c);
    xadd(x, k[1], tmp, DT/2.0);
    step(tmp, k[2], c);
    xadd(x, k[2], tmp, DT);
    step(tmp, k[3], c);
    for(int i=0;i<Nums;i++)
      for(int j=0;j<4;j++)
        x[i]+=k[j][i]*rate[j]*DT;
  }
  return 0;
}
