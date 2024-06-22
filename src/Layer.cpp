#include "tools.h"
#include "Neuron.h"
#include "Layer.h"
#include <list>

Layer::Layer(LType ntype,int NIL,ActivateFunction ac){
	type = ntype;
	numNeuronsInLayer = NIL;
	LActivateFunction = ac;
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
}

void Layer::init(int numNInputs){
	for(int i=0;i<Neurons.size();i++){
		getL(i,Neurons).init(numNInputs);
	}
}

int Layer::getNumNeuronsInLayer(){
	return numNeuronsInLayer;
}

list<double> Layer::getInputs(){
 return getL(0,Neurons).getInputs();
}

list<list<double>> Layer::getLWeights(){
	list<list<double>> weights;
	for(int i=0;i<Neurons.size();i++){
		weights.push_back(getL(i,Neurons).getWeights());
	}
	return weights;
}

list<double> Layer::getBiases(){
	list<double> biases;
	for(int i=0;i<Neurons.size();i++){
		biases.push_back(getL(i,Neurons).getBias());
	}
	return biases;
}

list<double> Layer::getLKs(){
	list<double> ks;
	for(int i=0;i<Neurons.size();i++){
		ks.push_back(getL(i,Neurons).getK());
	}
	return ks;
}

list<double> Layer::getLBs(){
	list<double> bs;
	for(int i=0;i<Neurons.size();i++){
		bs.push_back(getL(i,Neurons).getB());
	}
	return bs;
}

ActivateFunction Layer::getActivateFunction(){
	return LActivateFunction;
}

void Layer::setNumNeuronsInLayer(int nNIL){
	numNeuronsInLayer = nNIL;
}

void Layer::setInputs(list<double> ninputs){
	for(int i=0;i<Neurons.size();i++){
		getL(i,Neurons).setInputs(ninputs);
	}
}

void Layer::setLWeights(list<list<double>> nweights){
	for(int i=0;i<Neurons.size();i++){
		getL(i,Neurons).setWeights(getL(i,nweights));
	}
}

void Layer::setBiases(list<double> nbiases){
	for(int i=0;i<nbiases.size();i++){
		getL(i,Neurons).setBias(getL(i,nbiases));
	}
}

void Layer::setLKs(list<double> nlks){
	for(int i=0;i<nlks.size();i++){
		getL(i,Neurons).setK(getL(i,nlks));
	}
}

void Layer::setLBs(list<double> nlbs){
	for(int i=0;i<nlbs.size();i++){
		getL(i,Neurons).setB(getL(i,nlbs));
	}
}

void Layer::setActivateFunction(ActivateFunction ac){
	LActivateFunction = ac;
	for(int i=0;i<numNeuronsInLayer;i++){
		getL(i,Neurons).setActivateFunction(LActivateFunction);
	}
}

