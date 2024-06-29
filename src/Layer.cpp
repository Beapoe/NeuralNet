#include "tools.h"
#include "Neuron.h"
#include "Layer.h"
#include <list>

Layer::Layer(){}

Layer::Layer(LType ntype, int NIL, ActivateFunction ac)
{
    type = ntype;
	numNeuronsInLayer = NIL;
	for(int i=0;i<numNeuronsInLayer;i++){
		switch (type){
			case input:Neurons.push_back(Neuron(1));
					   break;
			case hidden:Neurons.push_back(Neuron());
						break;
			case output:Neurons.push_back(Neuron());
						break;
		}
	}
	Layer::setActivateFunction(ac);
}

void Layer::init(int numNInputs){
	for(int i=0;i<Neurons.size();i++){
		Neurons[i].init(numNInputs);
	}
}

int Layer::getNumNeuronsInLayer(){
	return numNeuronsInLayer;
}

vector<double> Layer::getInputs(){
 return Neurons[0].getInputs();
}

vector<vector<double>> Layer::getLWeights(){
	vector<vector<double>> weights;
	for(int i=0;i<Neurons.size();i++){
		weights.push_back(Neurons[i].getWeights());
	}
	return weights;
}

vector<double> Layer::getBiases(){
	vector<double> biases;
	for(int i=0;i<Neurons.size();i++){
		biases.push_back(Neurons[i].getBias());
	}
	return biases;
}

vector<double> Layer::getLKs(){
	vector<double> ks;
	for(int i=0;i<Neurons.size();i++){
		ks.push_back(Neurons[i].getK());
	}
	return ks;
}

vector<double> Layer::getLBs(){
	vector<double> bs;
	for(int i=0;i<Neurons.size();i++){
		bs.push_back(Neurons[i].getB());
	}
	return bs;
}

vector<double> Layer::getLOutputs()
{
	vector<double> result;
	for(auto i:Neurons){
		i.calc();
		result.push_back(i.getOutput());
	}
    return result;
}

ActivateFunction Layer::getActivateFunction(){
	return LActivateFunction;
}

void Layer::setNumNeuronsInLayer(int nNIL){
	numNeuronsInLayer = nNIL;
}

void Layer::setInputs(vector<double> ninputs){
	for(int i=0;i<Neurons.size();i++){
		Neurons[i].setInputs(ninputs);
	}
}

void Layer::setInput(vector<double> ninput){
	int counter = 0;
	for(auto i:ninput){
		Neurons[counter].setInput(i);
		counter++;
	}
}

void Layer::setLWeights(vector<vector<double>> nweights){
	for(int i=0;i<Neurons.size();i++){
		Neurons[i].setWeights(nweights[i]);
	}
}

void Layer::setBiases(vector<double> nbiases){
	for(int i=0;i<nbiases.size();i++){
		Neurons[i].setBias(nbiases[i]);
	}
}

void Layer::setLKs(vector<double> nlks){
	for(int i=0;i<nlks.size();i++){
		Neurons[i].setK(nlks[i]);
	}
}

void Layer::setLBs(vector<double> nlbs){
	for(int i=0;i<nlbs.size();i++){
		Neurons[i].setB(nlbs[i]);
	}
}

void Layer::setActivateFunction(ActivateFunction ac){
	LActivateFunction = ac;
	for(int i=0;i<numNeuronsInLayer;i++){
		Neurons[i].setActivateFunction(LActivateFunction);
	}
}

