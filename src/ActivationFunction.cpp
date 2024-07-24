#include "ActivationFunction.h"

double HyperTan(const double input)
{
	return (exp(input) - exp(-input)) / 2;
}

double HardThreshold(const double input)
{
	double value;
	if (input > 1)
	{
		value = input;
	}
	if (input < 1)
	{
		value = 0;
	}
	return value;
	;
}

double Relu(const double input)
{
	if (input > 0)
	{
		return input;
	}
	else
	{
		return 0;
	}
}

vector<double> Softmax(const vector<double>& raw){
    vector<double> pro(raw.size());
    double denominator;
    double e = exp(1);
    for(int i=0;i<raw.size();i++){
        denominator += pow(e,raw[i]);
    }
    for(int i=0;i<raw.size();i++){
        pro[i] = pow(e,raw[i])/denominator;
    }
    return pro;
}
double Leaky_Relu(const double input)
{
	return max(0.01 * input, input);
}
