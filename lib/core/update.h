#ifndef UPDAT_H
#define UPDAT_H

#include "../plug/myPlug.h"
class Runner:RuleHandler{
private:
  double *x[2],*k[4][2],*tmp[2],DT=0;
  const double tWeight[3]={0.5,0.5,1.0};
  const double kWeight[4]={1./6.,1./3.,1./3.,1./6.};
  void getK(int point);
  void update();
public:
  Runner();
  Runner(const double* Args);
  ~Runner();
  double* update(double dt,int times=1);
};

#endif
