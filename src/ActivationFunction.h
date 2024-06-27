#ifndef ACFUNC_H_
#define ACFUNC_H_
#include "tools.h"
#include <vector>
struct Args
{
    AType type;
    double value;
};
struct Arguements
{
    ActivateFunction type;
    vector<Args> arguemnts;
};
class ActivationFunction{
    public:
        virtual double execute(Arguements args) = 0;
};

#endif