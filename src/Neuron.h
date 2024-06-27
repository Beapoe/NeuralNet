#ifndef NEURON_H
#define NEURON_H

#include <cstdlib>
#include <random>
#include <ctime>
#include "tools.h"
#include "Linear.h"
#include "ActivationFunction.h"
using namespace std;

class Neuron{
	private:
	    // 定义输入的个数
		int numInputs = 1;
		// 定义偏置，线性激活函数的偏置，输出
		double bias,output;
		// 声明输入，权重列表
		vector<double> inputs,weights;
		// 激活函数相关参数
		Arguements args;
	public:
		// 构建空白神经元
		Neuron();
		// 构建带有随机偏置和权重的神经元
		Neuron(int numInputs);
		// 初始化空白神经元
		void init(int numInputs);
		// 计算输出
		void calc();
		// 获取偏置
		double getBias();
		// 获取线性激活函数的斜率
		double getK();
		// 获取线性激活函数的截距
		double getB();
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
		void setBias(double nbias);
		// 设置线性激活函数的斜率
		void setK(double nk);
		// 设置线性激活函数的截距
		void setB(double nb);
		// 设置隐含或输出输入
		void setInputs(vector<double> ninputs);
		// 设置输入层输入
		void setInput(double ninput);
		// 设置权重
		void setWeights(vector<double> nweights);
		// 设置激活函数
		void setActivateFunction(ActivateFunction nac);
		// 设置输入个数
		void setNumInputs(int nnuminputs);
};

#endif
