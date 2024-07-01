#ifndef ACFUNC_H_
#define ACFUNC_H_

#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

double HyperTan(double input);
double HardThreshold(double input);
double Relu(double input);
vector<double> Softmax(vector<double> RawOutput);
double Leaky_Relu(double input);



enum LType
{
    input,
    hidden,
    output
};
enum ActivateFunction
{
    null,
    hyperTan,
    hardThreshold,
    relu,
    softmax,
    leaky_relu
};

#endif