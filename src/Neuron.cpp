#include "Neuron.h"
using namespace std;

void n_init(Neuron& n,const int numInputs)
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
			n.n_bias = b(gen);
			countinue = false;
		}
		n.n_weights.push_back(w(gen));
	}
}

void n_calc(Neuron& n)
{
	if (n.n_inputs.size() != 0)
	{
		double total;
		for (int i = 0; i < n.n_inputs.size(); i++)
		{
			total += n.n_inputs[i] * n.n_weights[i];
		}
		total = total - n.n_bias;
		if (n.n_AC != null)
		{
			switch (n.n_AC)
			{
			case hyperTan:
				n.n_output = HyperTan(total);
				break;
			case hardThreshold:
				n.n_output = HardThreshold(total);
				break;
			case relu:
				n.n_output = Relu(total);
				break;
			case leaky_relu:
				n.n_output = Leaky_Relu(total);
				break;
			}
		}
		else
		{
			n.n_output = total;
		}
	}
}

double n_getBias(Neuron& n)
{
	return n.n_bias;
}

double n_getOutput(Neuron& n)
{
	return n.n_output;
}

vector<double,gc_allocator<double>> n_getInputs(Neuron& n)
{
	return n.n_inputs;
}

vector<double,gc_allocator<double>> n_getWeights(Neuron& n)
{
	return n.n_weights;
}

ActivateFunction n_getActivateFunction(Neuron& n)
{
	return n.n_AC;
}

int n_getNumInputs(Neuron& n)
{
	return n.n_num_inputs;
}

void n_setBias(Neuron& n,const double nbias)
{
	n.n_bias = nbias;
}

void n_setInputs(Neuron& n,const vector<double,gc_allocator<double>> &ninputs)
{
	n.n_inputs = ninputs;
}

void n_setInput(Neuron& n,const double ninput)
{
	n.n_inputs.clear();
	n.n_inputs.push_back(ninput);
}

void n_setWeights(Neuron& n,const vector<double,gc_allocator<double>> &nweights)
{
	n.n_weights = nweights;
}

void n_setActivateFunction(Neuron& n,const ActivateFunction &nac)
{
	n.n_AC = nac;
}

void n_setNumInputs(Neuron& n,int nnuminputs)
{
	n.n_num_inputs = nnuminputs;
}
