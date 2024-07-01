#ifndef _LAYER_H
#define _LAYER_H

#include "ActivationFunction.h"
#include "Neuron.h"

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
public:
	// 构建空白层
	Layer();
	// 构建含有层类型，层中神经元数目，神经元初始激活函数
	Layer(LType ntype, int NIL, ActivateFunction ac);
	// 初始化空白层
	void init(int numNInLayer);
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
	void setInputs(vector<double> ninputs);
	// 设置输入层输入
	void setInput(vector<double> ninput);
	// 设置输入个数
	void setNumInputs(int nNI);
	// 设置各个神经元权重
	void setLWeights(vector<vector<double>>);
	// 设置各个神经元的偏置
	void setBiases(vector<double> nbiases);
	// 设置层的初始激活函数
	void setActivateFunction(ActivateFunction nlac);
	// 设置层中神经元数目
	void setNumNeuronsInLayer(int nNIL);
};

#endif
