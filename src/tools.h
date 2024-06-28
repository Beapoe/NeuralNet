#ifndef TOOLS_H
#define TOOLS_H

#include <list>
#include <cmath>
#include <variant>
using namespace std;
enum LType {input,hidden,output};
enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};

double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif