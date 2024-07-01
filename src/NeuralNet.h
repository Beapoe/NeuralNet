#ifndef NEURALNET_H_
#define NEURALNET_H_

#include "Layer.h"
#include "ActivationFunction.h"
#include "DataSet.h"
#include "FADBAD-master/fadiff.h"
using namespace std;
typedef fadbad::F<double> FDouble;

class NeuralNet
{
public:
    // 构造函数，初始化神经网络
    NeuralNet();
    // 构造函数，根据参数初始化神经网络
    NeuralNet(int Nnum_hidden_layers, int Nnum_output_layer, int num_inputNeurons, vector<int> nums_hiddenNeurons, int num_outputNeurons,vector<ActivateFunction> ahac,ActivateFunction oac);
    // 训练神经网络
    void train();
    // 测试神经网络
    double Test();
    // 预测神经网络
    void predict(vector<double> inputs);
    // 保存神经网络参数
    void save();
    // 加载神经网络参数
    void load();
    // 获取学习率
    double getLearningRate();
    // 获取最大训练轮数
    int getMaxEpoch();
    // 获取输入层激活函数
    ActivateFunction getInputLayerAcFunc();
    // 获取所有隐藏层激活函数
    vector<ActivateFunction> getAllHiddenLayerAcFunc();
    // 获取隐藏层激活函数
    ActivateFunction getHiddenLayerAcFunc(int id);
    // 获取输出层激活函数
    ActivateFunction getOutputLayerAcFunc();
    // 获取输入数据
    vector<double> getInputs();
    // 获取输出
    vector<double> getOuputs();
    // 获取目标数据
    vector<double> getTargets();
    // 获取训练图像数据
    vector<vector<double>> getTrainImaageData();
    // 获取测试图像数据
    vector<vector<double>>getTestImageData();
    // 获取训练标签数据
    vector<double> getTrainLabelData();
    // 获取测试标签数据
    vector<double> getTestLabelData();
    // 获取打印测试准确率判定
    bool getPrintTestAccuracy();
    // 获取打印训练损失
    bool getPrintTrainLoss();
    // 设置学习率
    void setLearningRate(double nlearningRate);
    // 设置训练轮数
    void setMaxEpoch(int epoch);
    // 设置输入层激活函数
    void setInputLayerAcFunc(ActivateFunction niac);
    // 设置所有隐藏层激活函数
    void setAllHiddenLayerAcFunc(vector<ActivateFunction> nahac);
    // 设置隐藏层激活函数
    void setHiddenLayerAcFunc(int id, ActivateFunction);
    // 设置输出层激活函数
    void setOutputLayerAcFunc(ActivateFunction noac);
    // 设置输入数据
    void setInputs(vector<double> ninputs);
    // 设置目标数据
    void setTargets(vector<double> ntargets);
    // 设置训练数据
    void setData(DataSet& set);
    // 设置打印测试准确率判定
    void setPrintTestAccuracy(bool adjustment);
    // 设置打印训练损失判定
    void setPrintTrainLoss(bool adjustment);

private:
// 是否打印训练中损失
bool PrintTrainLoss;
// 是否打印测试准确值
bool PrintTestAccuracy;
    // 训练图像数据
    vector<vector<double>> TrainImageData;
    // 测试图像数据
    vector<vector<double>> TestImageData;
    // 训练标签数据
    vector<double> TrainLabelData;
    // 测试标签数据
    vector<double> TestLabelData;
    // 定义隐藏层的数量
    int num_hidden_layers;
    // 定义输出层的数量
    int num_output_layer;
    // 输入层
    Layer inputLayer;
    // 隐藏层
    vector<Layer> hiddenLayers;
    // 输出层
    Layer outputLayer;
    // 学习率
    double learningRate;
    // 最大训练轮数
    int maxepoch;
    // 输入层激活函数
    ActivateFunction iac;
    // 所有隐藏层激活函数
    vector<ActivateFunction> ahac;
    // 输出层激活函数
    ActivateFunction oac;
    // 输入数据
    vector<double> inputs;
    // 输出
    vector<double> outputs;
    // 目标数据
    vector<double> targets;
    // 损失
    FDouble loss;
    // 定义交叉熵损失函数
    FDouble CCE(vector<FDouble> outputs, FDouble targets);
    // 定义前向传播函数
    void forwardPropagation();
    // 定义反向传播函数
    void backwardPropagation(int current_batch);
    // 转化函数
    vector<FDouble> convert(vector<double> inputs);
};
#endif