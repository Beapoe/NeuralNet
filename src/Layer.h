#ifndef _LAYER_H
#define _LAYER_H

#include <list>
#include "tools.h"
#include "Neuron.h"

class Layer{
	private:
	    // 定义本层中神经元个数
		int numNeuronsInLayer;
		// 定义本层类型
		LType type;
		// 定义神经元列表
		list<Neuron> Neurons;
		// 定义本层神经元初始激活函数
		ActivateFunction LActivateFunction;
	public:
	    // 构建空白层
		Layer();
	    // 构建含有层类型，层中神经元数目，神经元初始激活函数
		Layer(LType ntype,int NIL,ActivateFunction ac);
		// 初始化空白层
		void init(int numNInLayer);
		// 获取层中神经元数目
		int getNumNeuronsInLayer();
		// 获取各个神经元输出
		list<double> getInputs();
		// 获取各个神经元权重
		list<list<double>> getLWeights();
		// 获取各个神经元偏置
		list<double> getBiases();
		// 获取层中线性激活函数的斜率
		list<double> getLKs();
		// 获取层中线性激活函数的截距
		list<double> getLBs();
		// 获取各个神经元输出
		list<double> getLOutputs();
		// 获取层初始激活函数
		ActivateFunction getActivateFunction();
		void setInputs(list<double> ninputs);
		// 设置各个神经元权重
		void setLWeights(list<list<double>>);
		// 设置各个神经元的偏置
		void setBiases(list<double> nbiases);
		// 设置层中线性激活函数的截距
		void setLKs(list<double> nlks);
		// 设置层中线性激活函数的斜率
		void setLBs(list<double> nlbs);
		// 设置层的初始激活函数
		void setActivateFunction(ActivateFunction nlac);
		// 设置层中神经元数目
		void setNumNeuronsInLayer(int nNIL);
};

#endif
