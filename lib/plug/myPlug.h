#ifndef MYPLUG_H
#define MYPLUG_H

enum ValuName{P,Q,Num};
class RuleHandler{
private:
  double m,a;
protected:
  int dimantion;
  void init(double *x[2]);
public:
  void runDynomic(double* x[2],double* v[2]);
  RuleHandler();
};

#endif
