#ifndef UPDAT_H
#define UPDAT_H

#include "../plug/myPlug.h"
class Runner:RuleHandler{
private:
  double *x[2],*k[4][2],*tmp[2],DT=0;
  const double tWeight[3]={0.5,0.5,1.0};
  const double kWeight[4]={1./6.,1./3.,1./3.,1./6.};
  void getK(int point);
public:
  Runner();
  ~Runner();
  double* update(double dt);
};

#endif
