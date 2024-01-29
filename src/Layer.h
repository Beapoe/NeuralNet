#ifndef _LAYER_H
#define _LAYER_H

#include <list>
#include "tools.h"
#include "Neuron.h"

class Layer{
	private:
		int numNeuronsInLayer;
		LType type;
		list<Neuron> Neurons;
		ActivateFunction LActivateFunction;
	public:
		Layer(LType ntype,int NIL,ActivateFunction ac);
		void init(int numNInLayer);
		int getNumNeuronsInLayer();
		list<double> getInputs();
		list<list<double>> getLWeights();
		list<double> getBiases();
		list<double> getLKs();
		list<double> getLBs();
		list<double> getLOutputs();
		ActivateFunction getActivateFunction();
		void setInputs(list<double> ninputs);
		void setLWeights(list<list<double>>);
		void setBiases(list<double> nbiases);
		void setLKs(list<double> nlks);
		void setLBs(list<double> nlbs);
		void setActivateFunction(ActivateFunction nlac);
		void setNumNeuronsInLayer(int nNIL);
};

#endif
