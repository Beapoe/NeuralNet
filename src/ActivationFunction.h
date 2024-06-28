#ifndef ACFUNC_H_
#define ACFUNC_H_

#include <cmath>
#include <map>
#include <functional>
using namespace std;

double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);

enum LType {input,hidden,output};
enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};

#endif