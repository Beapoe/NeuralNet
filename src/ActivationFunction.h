#ifndef ACFUNC_H_
#define ACFUNC_H_

#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include "bdwgc/include/gc/gc_allocator.h"
using namespace std;

double HyperTan(const double input);
double HardThreshold(const double input);
double Relu(const double input);
vector<double,gc_allocator<double>> Softmax(const vector<double,gc_allocator<double>> &raw);
double Leaky_Relu(const double input);

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