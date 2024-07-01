#include "ActivationFunction.h"

double HyperTan(double input)
{
	return (exp(input) - exp(-input)) / 2;
}

double HardThreshold(double input)
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

double Relu(double input)
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

vector<double> Softmax(vector<double> RawOutput)
{
    double max = *max_element(RawOutput.begin(), RawOutput.end());
	vector<double> output(RawOutput.size());
	for(size_t i=0;i<RawOutput.size();++i){
		output[i] = exp(RawOutput[i] - max);
	}
	double sum = std::accumulate(output.begin(), output.end(), 0.0);
	for(size_t i=0;i<output.size();++i){
		output[i] /= sum;
	}
	return output;
}

double Leaky_Relu(double input)
{
    return max(0.01*input, input);
}
