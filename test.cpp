#include "src/Layer.h"
#include "src/DataSet.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    Layer layer =  Layer(input,7,linear);
    layer.init(2);
    int number = layer.getNumNeuronsInLayer();
    cout<<number<<endl;
    DataSet set = DataSet();
    set.LoadEMnist();
    vector<vector<double>> data1 = set.getTestImages();
    vector<double> data2 = set.getTestLabels();
    cout<<data1.size()<<endl;
    cout<<data2.size()<<endl;
    cout<<data1[2].size()<<endl;
    return 0;
}