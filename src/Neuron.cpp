#include "Neuron.h"
using namespace std;

Neuron::Neuron(){}
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
		for(int i=0;i<inputs.size();i++){
			if(i == inputs.size()){
				total += bias*weights[i];
			}
			else{
				total += inputs[i]*weights[i];
			}
		}
		Args arg{i,total};
		args.arguemnts.push_back(arg);
		switch (args.type){
			case linear:{Linear AcFunc = Linear();
						output = AcFunc.execute(args);
						break;}
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
	return args.type;
}

void Neuron::setBias(double nbias){
	bias = nbias;
}

void Neuron::setK(double nk){
	Args arg{k,nk};
	args.arguemnts.push_back(arg);
}

void Neuron::setB(double nb){
	Args arg{b,nb};
	args.arguemnts.push_back(arg);
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
	args.type = nac;
}

void Neuron::setNumInputs(int nnuminputs){
	numInputs =nnuminputs;
}
