#include "update.h"
Runner::Runner(){
  for(auto &i:x)i=new double[dimantion];
  for(auto &i:tmp)i=new double[dimantion];
  for(auto &i:k)for(auto &j:i)j=new double[dimantion];
  init(x);
}
Runner::Runner(const double* Args):RuleHandler(Args){
  for(auto &i:x)i=new double[dimantion];
  for(auto &i:tmp)i=new double[dimantion];
  for(auto &i:k)for(auto &j:i)j=new double[dimantion];
  init(x);
}
Runner::~Runner(){
  for(auto &i:x)delete[] i;
  for(auto &i:tmp)delete[] i;
  for(auto &i:k)for(auto &j:i)delete[] j;
}
void Runner::getK(int point){
  for(int i=0;i<Num;i++)
    for(int j=0;j<dimantion;j++)
      tmp[i][j]=x[i][j]+k[point][i][j]*tWeight[point]*DT;
  runDynomic(tmp, k[point+1]);
}
void Runner::update(){
  runDynomic(x, k[0]);
  getK(0);getK(1);getK(2);
  for(int i=0;i<4;i++)
    for(int j=0;j<2;j++)
      for(int kk=0;kk<dimantion;kk++)
        x[j][kk]+=k[i][j][kk]*kWeight[i]*DT;
  return;
}
double* Runner::update(double dt,int times){
  DT=dt/(double)times;
  for(int i=1;i<=times;i++)update();
  return outPut(x[Q]);
}
