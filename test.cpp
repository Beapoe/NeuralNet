#include "src/NeuralNet.h"
#include "src/DataSet.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    DataSet set = DataSet();
    set.LoadEMnist();
    vector<int> num_h_neurons = {10,5};
    vector<ActivateFunction> ahac = {leaky_relu,hyperTan};
    NeuralNet nn(2,1,784,num_h_neurons,10,ahac,relu);
    nn.setData(set);
    nn.setLearningRate(0.2);
    nn.setMaxEpoch(1000);
    nn.setPrintTestAccuracy(true);
    nn.train();
    return 0;
}