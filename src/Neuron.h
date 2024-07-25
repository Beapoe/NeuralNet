#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cstdlib>
#include <random>
#include <thread>
#include <chrono>
#include "ActivationFunction.h"
#include "bdwgc/include/gc/gc_allocator.h"
using namespace std;
struct Neuron{
    //定义输入
    vector<double,gc_allocator<double>> n_inputs;
	//定义权重
    vector<double,gc_allocator<double>> n_weights;
    //定义输入个数
    int n_num_inputs;
    //定义偏置
    double n_bias;
    //定义输出
    double n_output;
    // 定义激活函数
	ActivateFunction n_AC;
};

void n_init(Neuron& n,const int numINputs);
void n_calc(Neuron& n);
double n_getBias(Neuron& n);
double n_getOutput(Neuron& n);
vector<double,gc_allocator<double>> n_getInputs(Neuron& n);
vector<double,gc_allocator<double>> n_getWeights(Neuron& n);
ActivateFunction n_getActivateFunction(Neuron& n);
int n_getNumInputs(Neuron& n);
void n_setBias(Neuron& n,const double nbias);
void n_setInputs(Neuron& n,const vector<double,gc_allocator<double>>& ninputs);
void n_setInput(Neuron& n,const double ninput);
void n_setWeights(Neuron& n,const vector<double,gc_allocator<double>>& nweights);
void n_setActivateFunction(Neuron& n,const ActivateFunction& nac);
void n_setNumInputs(Neuron& n,const int nnuminputs);
#endif
