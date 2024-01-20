#include <list>
#include "tools.h"
#include "Neuron.h"
using namespace std;

class Layer{
	private:
		int numNeuronsInLayer;
		LType type;
		list<Neuron> Neurons;
		ActivateFunction LActivateFunction;
	public:
		Layer(LType ntype,int NIL,ActivateFunction ac);
		void init(numInputs);
		list<list<double>> getInputs();
		list<list<double>> getWeights();
		list<double> getBiases();
		list<double> getKs();
		list<double> getBs();
		list<double> getOutputs();
		ActivateFunction getActivateFunction();
		int getNumNeuronsInLayer();
		void setInputs(list<list<double>> ninputs);
		void setWeights(list<list<double>> nweights);
		void setBiases(list<double> nbiases);
		void setKs(list<double> nks);
		void setBs(list<double> nbs);
		ActivateFunction setActivateFunction(ActivateFunction nac);
		void setNumNeuronsInLayer(int nNIL);
};
