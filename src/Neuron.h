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

class Neuron
{
private:
	// 定义输入的个数
	int numInputs;
	// 定义偏置
	double bias;
	// 输出
	double output;
	// 声明输入，权重列表
	vector<double,gc_allocator<double>> inputs, weights;
	// 定义激活函数
	ActivateFunction AC;

public:
	Neuron();
	// 构建带有随机偏置和权重的神经元
	Neuron(const int numInputs);
	// 初始化空白神经元
	void init(const int numInputs);
	// 计算输出
	void calc();
	// 获取偏置
	double getBias();
	// 获取输出
	double getOutput();
	// 获取输入
	vector<double,gc_allocator<double>> getInputs();
	// 获取权重
	vector<double,gc_allocator<double>> getWeights();
	// 获取激活函数
	ActivateFunction getActivateFunction();
	// 设置输入个数
	int getNumInputs();
	// 设置偏置
	void setBias(const double nbias);
	// 设置隐含层或输出层输入
	void setInputs(const vector<double,gc_allocator<double>> &ninputs);
	// 设置输入层的输入
	void setInput(const double ninput);
	// 设置权重
	void setWeights(const vector<double,gc_allocator<double>> &nweights);
	// 设置激活函数
	void setActivateFunction(const ActivateFunction &nac);
	// 设置输入个数
	void setNumInputs(const int nnuminputs);
};

struct Neuron{
    //定义输入
    vector<double,gc_allocator<double>> neuron_inputs;
    //定义输入个数
    int neuron_num_inputs;
    //定义偏置
    double neuron_bias;
    //定义输出
    double neuron_output
    //定义权重
    vector<double,gc_allocator<double>> neuron_weights
}
#endif
