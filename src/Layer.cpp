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
		getL(i,"n",Neurons).init(numNInputs);
	}
}

int Layer::getNumNeuronsInLayer(){
	return numNeuronsInLayer;
}

list<double> Layer::getInputs(){
	list<double> inputs;
	for(int i=0;i<Neurons.size();i++){
		inputs.push_back(getL(i,"n",Neurons).getInputs());
	}
	return inputs;
}

list<list<double>> Layer::LWeights(){
	list<list<double>> weights;
	for(int i=0;i<Neurons.size();i++){
		weights.push_back(getL(i,"n",Neurons).getWeights());
	}
	return weights;
}

list<double> Layer::getBiases(){
	list<double> biases;
	for(int i=0;i<Neurons.size();i++){
		biases.push_back(getL(i,"n",Neurons).getBias());
	}
}

list<double> Layer::getLKs(){
	list<double> ks;
	for(int i=0;i<Neurons.size();i++){
		ks.push_back(getL(i,"n",Neurons).getK());
	}
	return ks;
}

list<double> Layer::getLBs(){
	list<double> bs;
	for(int i=0;i<Neurons.size();i++){
		bs.push_back(getL(i,"n",Neurons).getB());
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
		getL(i,"n",Neurons).setInputs(ninputs);
	}
}

void Layer::setLWeights(list<list<double>> nweights){
	for(int i=0;i<Neurons.size();i++){
		getL(i,"n",Neurons).setWeights(getL(i,"l<d>",nweights));
	}
}
