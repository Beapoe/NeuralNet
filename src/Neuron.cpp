#include "Neuron.h"
using namespace std;

Neuron::Neuron() {}
Neuron::Neuron(int numInputs)
{
	random_device rd;
	double weight, nbias;
	uniform_real_distribution<double> w(-1, 1);
	uniform_real_distribution<double> b(0, 1);
	mt19937 gen(rd());
	bool countinue = true;
	for (int i = 0; i < numInputs && countinue; i++)
	{
		if (i == numInputs)
		{
			nbias = b(gen);
			bias = nbias;
			countinue = false;
		}
		weight = w(gen);
		weights.push_back(weight);
	}
}

void Neuron::init(int numInputs)
{
	random_device rd;
	double weight, nbias;
	uniform_real_distribution<double> w(-1, 1);
	uniform_real_distribution<double> b(0, 1);
	mt19937 gen(rd());
	bool countinue = true;
	for (int i = 0; i < numInputs && countinue; i++)
	{
		if (i == numInputs)
		{
			nbias = b(gen);
			bias = nbias;
			countinue = false;
		}
		weight = w(gen);
		weights.push_back(weight);
	}
}

void Neuron::calc()
{
	if (inputs.size() != 0)
	{
		double total;
		for (int i = 0; i < inputs.size(); i++)
		{
			total += inputs[i] * weights[i];
		}
		total = total - bias;
		if (AC != null)
		{
			switch (AC)
			{
			case hyperTan:
				output = HyperTan(total);
				break;
			case hardThreshold:
				output = HardThreshold(total);
				break;
			case relu:
				output = Relu(total);
				break;
			case leaky_relu:
				output = Leaky_Relu(total);
				break;
			}
		}
		else
		{
			output = total;
		}
	}
}


double Neuron::getBias()
{
	return bias;
}

double Neuron::getOutput()
{
	return output;
}

vector<double> Neuron::getInputs()
{
	return inputs;
}

vector<double> Neuron::getWeights()
{
	return weights;
}

ActivateFunction Neuron::getActivateFunction()
{
	return AC;
}

int Neuron::getNumInputs()
{
    return numInputs;
}

void Neuron::setBias(double nbias)
{
	bias = nbias;
}

void Neuron::setInputs(vector<double> ninputs)
{
	inputs = ninputs;
}

void Neuron::setInput(double ninput)
{
	inputs.push_back(ninput);
}

void Neuron::setWeights(vector<double> nweights)
{
	weights = nweights;
}

void Neuron::setActivateFunction(ActivateFunction nac)
{
	AC = nac;
}

void Neuron::setNumInputs(int nnuminputs)
{
	numInputs = nnuminputs;
}
