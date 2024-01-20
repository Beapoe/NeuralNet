#ifndef TOOLS_H
#define TOOLS_H
#include <list>
using namespace std;

enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};

double getDL(int index,list<double> l);
double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif
