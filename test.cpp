#include "src/Layer.h"
#include <iostream>
using namespace std;

int main(){
    Layer layer =  Layer(input,10,linear);
    layer.init(2);
    int number = layer.getNumNeuronsInLayer();
    cout<<number;
    return 0;
}