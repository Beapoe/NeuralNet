#ifndef _LAYER_H
#define _LAYER_H

#include "ActivationFunction.h"
#include "FADBAD-master/fadiff.h"
#include "Neuron.h"
typedef fadbad::F<double> FDouble;

class Layer
{
private:
	// 定义本层中神经元个数
	int numNeuronsInLayer;
	// 定义本层类型
	LType type;
	// 定义神经元列表
	vector<Neuron> Neurons;
	// 定义本层神经元初始激活函数
	ActivateFunction LActivateFunction;
	// 输出
	vector<double> Output;
	// 误差
	FDouble loss;

public:
	// 构建空白层
	Layer();
	// 析构函数
	~Layer();
	// 构建含有层类型，层中神经元数目，神经元初始激活函数
	Layer(const LType &ntype, const int NIL, const ActivateFunction &ac);
	// 初始化空白层
	void init(const int numNInputs);
	// 获取层中神经元数目
	int getNumNeuronsInLayer();
	// 获取各个神经元输出
	vector<double> getInputs();
	// 获取各个神经元权重
	vector<vector<double>> getLWeights();
	// 获取各个神经元偏置
	vector<double> getBiases();
	// 获取各个神经元输出
	vector<double> getLOutputs();
	// 获取输入个数
	int getNumInputs();
	// 获取层初始激活函数
	ActivateFunction getActivateFunction();
	// 设置隐含层和输出层输入
	void setInputs(const vector<double> &ninputs);
	// 设置输入层输入
	void setInput(const vector<double> &ninput);
	// 设置输入个数
	void setNumInputs(const int nNI);
	// 设置各个神经元权重
	void setLWeights(const vector<vector<double>> &nweights);
	// 设置各个神经元的偏置
	void setBiases(const vector<double> &nbiases);
	// 设置层的初始激活函数
	void setActivateFunction(const ActivateFunction &nlac);
	// 设置层中神经元数目
	void setNumNeuronsInLayer(const int nNIL);
};

#endif
