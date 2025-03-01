#include "myPlug.h"
#include <cmath>
#include <cstdio>
RuleHandler::RuleHandler(){
  m=1;a=1;dimantion=2;
}
void RuleHandler::init(double *x[2]){
  for(int i=0;i<2;i++)
    for(int j=0;j<dimantion;j++)
      x[i][j]=0;
  x[Q][0]=2;x[P][1]=0.2*m*pow(x[Q][0],2);
}
void RuleHandler::runDynomic(double *x[2],double *v[2]){
  v[Q][0]=x[P][0]/m;
  v[Q][1]=x[P][1]/m/pow(x[Q][0],2);
  v[P][0]=(pow(x[P][1],2)-a*m*x[Q][0])/m/pow(x[Q][0],3);
  v[P][1]=0;
}
