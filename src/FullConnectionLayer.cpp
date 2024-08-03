#include "FullConnectionLayer.h"

void FullConnectionLayer::setInputs(std::unique_ptr<double[]>ninputs){
    inputs = ninputs;
}

void FullConnectionLayer::setWeights(matrix<double> nweights){
    weights = nweights;
}
void FullConnectionLayer::setBiases(std::unique_ptr<double[]> nbiases){
    biases = nbiases;
}
void FullConnectionLayer::setActivation(std::function<double(double)> nactivation){
    activation = nactivation;
}
std::unique_ptr<double[]> FullConnectionLayer::getInputs(){
    return inputs;
}
matrix<double> FullConnectionLayer::getWeights(){
    return weights;
}
std::unique_ptr<double[]> FullConnectionLayer::getBiases(){
    return biases;
}
std::function<double(double)> FullConnectionLayer::getActivation(){
    return activation;
}
