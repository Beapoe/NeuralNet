#include "src/Layer.h"
#include "src/DataSet.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    Layer layer =  Layer(input,7,linear);
    int number = layer.getNumNeuronsInLayer();
    cout<<number<<endl;
    DataSet set = DataSet();
    set.LoadEMnist();
    vector<vector<double>> data1 = set.getTestImages();
    vector<double> data2 = set.getTestLabels();
    cout<<data1.size()<<endl;
    cout<<data2.size()<<endl;
    cout<<data1[2].size()<<endl;
    vector<double> inputs;
    for (int i=0;i<7;i++)
    {
        inputs.push_back(45);
    }
    vector<double> bs,ks;
    for(int i=0;i<7;i++){
        bs.push_back(4.153629);
        ks.push_back(4.213594);
    }
    layer.setInput(inputs);
    layer.setLKs(ks);
    layer.setLBs(bs);
    vector<double> result = layer.getLOutputs();
    vector<double> baises = layer.getBiases();
    vector<vector<double>> weights = layer.getLWeights();
    for(auto i:result){
        cout<<i<<endl;
    }
    cout<<endl;
    for(auto i:baises){
        cout<<i<<endl;
    }
    cout<<endl;
    int counter = 0;
    for(auto i:weights){
        for(auto j:weights[counter]){
            cout<<j<<" ";
        }
        counter++;
        cout<<endl;
    }
    cout<<endl;
    return 0;
}