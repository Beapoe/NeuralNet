#include "src/NeuralNet.h"
#include "src/DataSet.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    const clock_t begin = clock();
    DataSet set = DataSet();
    set.LoadEMnist();
    vector<int,gc_allocator<int>> num_h_neurons = {10, 5};
    vector<ActivateFunction,gc_allocator<ActivateFunction>> ahac = {leaky_relu, hyperTan};
    NeuralNet nn(2, 10, 784, num_h_neurons, 10, ahac, relu);
    nn.setData(set);
    set.~DataSet();
    nn.setLearningRate(0.001);
    nn.setMaxEpoch(1000);
    nn.setPrintTestAccuracy(true);
    nn.setPrintTrainLoss(true);
    nn.train();
    cout << "Used time:" << (double)(clock() - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}