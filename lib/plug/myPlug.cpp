#include "myPlug.h"
#include <cmath>
#include <cstdio>
RuleHandler::RuleHandler(){
  l[0]=1;l[1]=2;
  m[0]=1;m[1]=1;
  g=9.8;dimantion=2;
  x0[0]=0;x0[1]=0;
}
RuleHandler::RuleHandler(const double* Args){
  l[0]=1;l[1]=2;
  m[0]=1;m[1]=1;
  g=9.8;dimantion=2;
  x0[0]=Args[0];x0[1]=Args[1];
}
void RuleHandler::init(double *x[2]){
  for(int i=0;i<2;i++)
    for(int j=0;j<dimantion;j++)
      x[i][j]=0;
  x[Q][0]=x0[0];x[Q][1]=x0[1];
}
void RuleHandler::runDynomic(double *x[2],double *v[2]){
  v[Q][0]=x[P][0]/pow(l[0],2)/m[0]
    +m[1]*x[P][0]/pow(l[0],2)/pow(m[0],2)
    +x[P][1]*cos(x[Q][0]-x[Q][1])/l[0]/l[1]/m[0]/2.;
  v[Q][1]=x[P][1]/pow(l[1],2)/m[1]
    +x[P][0]*cos(x[Q][0]-x[Q][1])/l[0]/l[1]/m[0]/2.;
  v[P][0]=x[P][0]*x[P][1]*sin(x[Q][0]-x[Q][1])/(2.*l[0]*l[1]*m[0])
    -g*l[0]*(m[0]+m[1])*sin(x[Q][0]);
  v[P][1]=-x[P][0]*x[P][1]*sin(x[Q][0]-x[Q][1])/(2*l[0]*l[1]*m[0])
    -g*l[1]*m[1]*sin(x[Q][1]);
}
double* RuleHandler::outPut(double *x){
  o[0]=l[0]*sin(x[0]);o[1]=l[0]*cos(x[0]);
  o[2]=l[1]*sin(x[1])+o[0];
  o[3]=l[1]*cos(x[1])+o[1];
  return o;
}
