#ifndef NEURON_H
#define NEURON_H

#include <list>
#include <cstdlib>
#include "tools.h"

class Neuron{
	private:
		int numInputs;
		double bias,k,b,output;
		list<double> inputs,weights;
		ActivateFunction AC;
	public:
		Neuron();
		Neuron(int numInputs);
		void init(int numInputs);
		void calc();
		double getBias();
		double getK();
		double getB();
		double getOutput();
		list<double> getInputs();
		list<double> getWeights();
		ActivateFunction getActivateFunction();
		int getNumInputs();
		void setBias(double nbias);
		void setK(double nk);
		void setB(double nb);
		void setInputs(list<double> ninputs);
		void setWeights(list<double> nweights);
		void setActivateFunction(ActivateFunction nac);
		void setNumInputs(int nnuminputs);
}
