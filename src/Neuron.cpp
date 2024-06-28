#include "Neuron.h"
using namespace std;

Neuron::Neuron(){}
Neuron::Neuron(int numInputs){
	random_device rd;
	double weight,nbias;
	uniform_real_distribution<double> u(-1,1);
	mt19937 gen(rd());
	bool countinue = true;
	for(int i=0;i<numInputs+1 && countinue;i++){
		if(i == numInputs){
			nbias = u(gen);
			bias = nbias;
			countinue = false;
		}
		weight = u(gen);
		weights.push_back(weight);
	}
}

void Neuron::init(int numInputs){
	random_device rd;
	double weight,nbias;
	uniform_real_distribution<double> u(-1,1);
	mt19937 gen(rd());
	bool countinue = true;
	for(int i=0;i<numInputs+1 && countinue;i++){
		if(i == numInputs){
			nbias = u(gen);
			bias = nbias;
			countinue = false;
		}
		weight = u(gen);
		weights.push_back(weight);
	}
}

void Neuron::calc(){
	if(inputs.size() != 0){
		double total;
		for(int i=0;i<inputs.size()+1;i++){
			if(i == inputs.size()){
				total += bias*weights[i];
			}
			else{
				total += inputs[i]*weights[i];
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

vector<double> Neuron::getInputs(){
	return inputs;
}

vector<double> Neuron::getWeights(){
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

void Neuron::setInputs(vector<double> ninputs){
    inputs = ninputs;
}

void Neuron::setInput(double ninput){
	inputs.push_back(ninput);
}

void Neuron::setWeights(vector<double> nweights){
	weights = nweights;
}

void Neuron::setActivateFunction(ActivateFunction nac){
	AC = nac;
}

void Neuron::setNumInputs(int nnuminputs){
	numInputs =nnuminputs;
}
