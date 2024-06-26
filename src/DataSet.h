#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
using namespace std;

class DataSet{
    private:
        // 训练集图像文件路径
        string TrainImagePath;
        // 测试集图像文件路径
        string TestImagePath;
        // 训练集标签文件路径
        string TrainLabelPath;
        // 测试集标签文件路径
        string TestLabelPath;
        // 训练集图像文件对象
        ifstream TrainImageFile;
        // 训练集标签文件对象
        ifstream TrainLabelFile;
        // 测试集图像文件对象
        ifstream TestImageFile;
        // 测试集标签文件对象
        ifstream TestLabelFile;
        // 训练集图像文件魔数
        int TrainImageMagicnum = 0;
        // 测试集图像文件魔数
        int TestImageMagicnum = 0;
        // 训练集标签文件魔数
        int TrainLabelMagicnum = 0;
        // 测试集标签文件魔数
        int TestLabelMagicnum = 0;
        // 测试集图像数目
        int TestImagesnum = 0;
        // 训练集图像数目
        int TrainImagesnum = 0;
        // 测试集标签数目
        int TestLabelsnum = 0;
        // 训练集标签数目
        int TrainLabelsnum = 0;
        // 测试集图像行数
        int TestImageRowsnum = 0;
        // 训练集图像行数
        int TrainImageRowsnum = 0;
        // 测试集图像列数
        int TestImageColsnum = 0;
        // 训练集图像列数
        int TrainImageColsnum = 0;
        // 训练集图像数据
        vector<vector<double>> TrainImages;
        //测试集图像数据
        vector<vector<double>> TestImages;
        // 训练集标签数据
        vector<double> Trainlabels;
        // 测试集标签数据
        vector<double> TestLabels;

        // 从文件流中读取大端序的整数
        int ReverseInt(int i);
        void preparePath();
        // 读取文件头
        void readHeader();
        // 读取图像数据
        void readImages();
        // 读取标签数据
        void readLabels();
    public:
        // 构建函数
        DataSet();
        // 载入EMnist数据集
        void LoadEMnist();
        // 获取训练集图像数据
        vector<vector<double>> getTrainImages();
        // 获取测试集图像数据
        vector<vector<double>> getTestImages();
        // 获取训练集标签数据
        vector<double> getTarinLabels();
        // 获取测试集标签数据
        vector<double> getTestLabels();
};