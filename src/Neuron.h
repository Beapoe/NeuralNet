#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cstdlib>
#include <random>
#include <thread>
#include <chrono>
#include "ActivationFunction.h"
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
	vector<double> inputs, weights;
	// 定义激活函数
	ActivateFunction AC;

public:
	Neuron();
	// 析构函数
	~Neuron();
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
	vector<double> getInputs();
	// 获取权重
	vector<double> getWeights();
	// 获取激活函数
	ActivateFunction getActivateFunction();
	// 设置输入个数
	int getNumInputs();
	// 设置偏置
	void setBias(const double nbias);
	// 设置隐含层或输出层输入
	void setInputs(const vector<double> &ninputs);
	// 设置输入层的输入
	void setInput(const double ninput);
	// 设置权重
	void setWeights(const vector<double> &nweights);
	// 设置激活函数
	void setActivateFunction(const ActivateFunction &nac);
	// 设置输入个数
	void setNumInputs(const int nnuminputs);
};

#endif