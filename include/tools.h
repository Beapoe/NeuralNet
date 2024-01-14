#ifndef TOOLS_H
#define TOOLS_H

enum ActivateFunction {Linear,Sigmoid,HyperTan,HardThreshold};

double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif
