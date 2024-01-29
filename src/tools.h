#ifndef TOOLS_H
#define TOOLS_H
#include <list>
#include <string>
using namespace std;
enum LType {input,hidden,output};
enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};

double getL(int index,string type,list<double> l);
double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif
