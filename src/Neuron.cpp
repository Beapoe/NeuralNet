#include "tools.h"
#include "Neuron.h"
#include <list>
#include <ctime>
#include <random>
#include <limits>
using namespace std;

Neuron::Neuron(int numInputs){
	default_random_engine e(time(0));
	double weight,nbias;
	double DMax = numeric_limits<double>::max();
	double DMin = numeric_limits<double>::min();
	uniform_real_distribution<double> u(DMin,DMax);
	for(int i=0;i<numInputs+1;i++){
		if(i == numInputs){
			nbias = u(e);
			bias = nbias;
			break;
		}
		weight = u(e);
		weights.push_back(weight);
	}
}

void Neuron::init(int numInputs){
	default_random_engine e(time(0));
	double weight,nbias;
	double DMax = numeric_limits<double>::max();
	double DMin = numeric_limits<double>::min();
	uniform_real_distribution<double> u(DMin,DMax);
	for(int i=0;i<numInputs+1;i++){
		if(i == numInputs){
			nbias = u(e);
			bias = nbias;
			break;
		}
		weight = u(e);
		weights.push_back(weight);
	}
}

void Neuron::calc(){
	if(inputs.size() != 0){
		double total;
		for(int i=0;i<=inputs.size();i++){
			if(i == inputs.size()){
				total += bias*getL(i,"d",weights);
			}
			else{
				total += getL(i,"d",inputs)*getL(i,"d",weights);
			}
		}
		switch (AC){
			case linear:output = Linear(k,b,total);
						break;
			case sigmoid:output = Sigmoid(total);
						 break;
			case hyperTan:output = HyperTan(total);
						  break;
			case hardThreshold:output = HardThreshold(total);
							   break;
		}
	}
}

double Neuron::getBias(){
	return bias;
}

double Neuron::getK(){
	return k;
}

double Neuron::getB(){
	return b;
}

double Neuron::getOutput(){
	return output;
}

list<double> Neuron::getInputs(){
	return inputs;
}

list<double> Neuron::getWeights(){
	return weights;
}

ActivateFunction Neuron::getActivateFunction(){
	return AC;
}

void Neuron::setBias(double nbias){
	bias = nbias;
}

void Neuron::setK(double nk){
	k = nk;
}

void Neuron::setB(double nb){
	b = nb;
}

void Neuron::setInputs(list<double> ninputs){
    inputs = ninputs;
}

void Neuron::setWeights(list<double> nweights){
	weights = nweights;
}

void Neuron::setActivateFunction(ActivateFunction nac){
	AC = nac;
}
