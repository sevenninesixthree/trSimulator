#ifndef MYPLUG_H
#define MYPLUG_H

enum ValuName{P,Q,Num};
class RuleHandler{
private:
  double m[2],g,l[2],o[4],x0[2];
protected:
  int dimantion;
  void init(double *x[2]);
  double* outPut(double *q);
public:
  void runDynomic(double* x[2],double* v[2]);
  RuleHandler(const double* Args);
  RuleHandler();
};

#endif
