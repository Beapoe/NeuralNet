#include "src/Layer.h"
#include "src/DataSet.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    Layer layer =  Layer(input,784,linear);
    int number = layer.getNumNeuronsInLayer();
    cout<<number<<endl;
    DataSet set = DataSet();
    set.LoadEMnist();
    vector<vector<double>> data1 = set.getTestImages();
    vector<double> data2 = set.getTestLabels();
    cout<<data1.size()<<endl;
    cout<<data2.size()<<endl;
    cout<<data1[2].size()<<endl;
    vector<double> TestData = data1[1];
    layer.setInput(TestData);
    vector<double> ks,bs;
    for(int i=0;i,784;i++){
        ks.push_back(9);
        bs.push_back(1);
    }
    layer.setLKs(ks);
    layer.setLBs(bs);
    vector<double> result = layer.getLOutputs();
    vector<double> biases = layer.getBiases();
    int counter = 1;
    for(auto i:result){
        cout<<i<<" ";
        if(counter == 28){
            cout<<endl;
            counter = 0;
        }
        counter++;
    }
    cout<<biases.size()<<endl;
    return 0;
}