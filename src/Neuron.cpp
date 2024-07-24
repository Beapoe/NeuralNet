#include "Neuron.h"
using namespace std;

Neuron::Neuron() {}
Neuron::Neuron(const int numInputs)
{
	random_device rd;
	double weight, nbias;
	uniform_real_distribution<double> w(-1, 1);
	uniform_real_distribution<double> b(0, 1);
	mt19937 gen(rd());
	bool countinue = true;
	for (int i = 0; i < numInputs && countinue; i++)
	{
		if (i == numInputs - 1)
		{
			bias = b(gen);
			countinue = false;
		}
		weight = w(gen);
		weights.push_back(weight);
	}
}

void Neuron::init(const int numInputs)
{
	random_device rd;
	double weight, nbias;
	uniform_real_distribution<double> w(-1, 1);
	uniform_real_distribution<double> b(0, 1);
	mt19937 gen(rd());
	bool countinue = true;
	for (int i = 0; i < numInputs && countinue; i++)
	{
		if (i == numInputs - 1)
		{
			bias = b(gen);
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

vector<double,gc_allocator<double>> Neuron::getInputs()
{
	return inputs;
}

vector<double,gc_allocator<double>> Neuron::getWeights()
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

void Neuron::setBias(const double nbias)
{
	bias = nbias;
}

void Neuron::setInputs(const vector<double,gc_allocator<double>> &ninputs)
{
	inputs = ninputs;
}

void Neuron::setInput(const double ninput)
{
	inputs.clear();
	inputs.push_back(ninput);
}

void Neuron::setWeights(const vector<double,gc_allocator<double>> &nweights)
{
	weights = nweights;
}

void Neuron::setActivateFunction(const ActivateFunction &nac)
{
	AC = nac;
}

void Neuron::setNumInputs(int nnuminputs)
{
	numInputs = nnuminputs;
}
