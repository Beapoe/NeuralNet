#include "DataSet.h"

int DataSet::ReverseInt(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return ((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

void DataSet::preparePath()
{
    string current_path = __FILE__;
    string toRemove = "DataSet.cpp";
    size_t pos = current_path.find(toRemove);
    bool condition = pos == string::npos;
    string public_path;
    if (condition == false)
    {
        public_path = current_path.erase(pos, toRemove.length()) + "mnist/";
    }
    TestImagePath = public_path + "emnist-mnist-test-images-idx3-ubyte";
    TestLabelPath = public_path + "emnist-mnist-test-labels-idx1-ubyte";
    TrainImagePath = public_path + "emnist-mnist-train-images-idx3-ubyte";
    TrainLabelPath = public_path + "emnist-mnist-train-labels-idx1-ubyte";
}
void DataSet::readHeader()
{
    TrainImageFile.open(TrainImagePath, ios::binary);
    if (!TrainImageFile.is_open())
    {
        std::cerr << "Error opening image file: " << TrainImagePath << std::endl;
    }
    TrainLabelFile.open(TrainLabelPath, ios::binary);
    if (!TrainLabelFile.is_open())
    {
        std::cerr << "Error opening label file: " << TrainLabelPath << std::endl;
    }
    TestImageFile.open(TestImagePath, ios::binary);
    if (!TestImageFile.is_open())
    {
        std::cerr << "Error opening image file: " << TestImagePath << std::endl;
    }
    TestLabelFile.open(TestLabelPath, ios::binary);
    if (!TestLabelFile.is_open())
    {
        std::cerr << "Error opening label file: " << TestLabelPath << std::endl;
    }
}

void DataSet::readImages()
{
    TrainImageFile.read((char *)&TrainImageMagicnum, sizeof(TrainImageMagicnum));
    TrainImageFile.read((char *)&TrainImagesnum, sizeof(TrainImagesnum));
    TrainImageFile.read((char *)&TrainImageRowsnum, sizeof(TrainImageRowsnum));
    TrainImageFile.read((char *)&TrainImageColsnum, sizeof(TrainImageColsnum));
    TestImageFile.read((char *)&TestImageMagicnum, sizeof(TestImageMagicnum));
    TestImageFile.read((char *)&TestImagesnum, sizeof(TestImagesnum));
    TestImageFile.read((char *)&TestImageRowsnum, sizeof(TestImageRowsnum));
    TestImageFile.read((char *)&TestImageColsnum, sizeof(TestImageColsnum));
    TrainImageMagicnum = DataSet::ReverseInt(TrainImageMagicnum);
    TrainImagesnum = DataSet::ReverseInt(TrainImagesnum);
    TrainImageRowsnum = DataSet::ReverseInt(TrainImageRowsnum);
    TrainImageColsnum = DataSet::ReverseInt(TrainImageColsnum);
    TestImageMagicnum = DataSet::ReverseInt(TestImageMagicnum);
    TestImagesnum = DataSet::DataSet::ReverseInt(TestImagesnum);
    TestImageRowsnum = DataSet::DataSet::ReverseInt(TestImageRowsnum);
    TestImageColsnum = DataSet::DataSet::ReverseInt(TestImageColsnum);
    for (int i = 0; i < TrainImagesnum; i++)
    {
        vector<double,gc_allocator<double>> temp;
        for (int r = 0; r < TrainImageRowsnum; r++)
        {
            for (int c = 0; c < TrainImageColsnum; c++)
            {
                unsigned char image = 0;
                TrainImageFile.read((char *)&image, sizeof(image));
                temp.push_back(image);
            }
        }
        TrainImages.push_back(temp);
    }
    for (int i = 0; i < TestImagesnum; i++)
    {
        vector<double,gc_allocator<double>> temp;
        for (int r = 0; r < TestImageRowsnum; r++)
        {
            for (int c = 0; c < TestImageColsnum; c++)
            {
                unsigned char image = 0;
                TestImageFile.read((char *)&image, sizeof(image));
                temp.push_back(image);
            }
        }
        TestImages.push_back(temp);
    }
}

void DataSet::readLabels()
{
    TrainLabelFile.read((char *)&TestLabelMagicnum, sizeof(TrainLabelMagicnum));
    TrainLabelFile.read((char *)&TrainLabelsnum, sizeof(TrainLabelsnum));
    TestLabelFile.read((char *)&TestLabelMagicnum, sizeof(TestLabelMagicnum));
    TestLabelFile.read((char *)&TestLabelsnum, sizeof(TestLabelsnum));
    TrainLabelMagicnum = DataSet::ReverseInt(TestLabelMagicnum);
    TrainLabelsnum = DataSet::DataSet::ReverseInt(TrainLabelsnum);
    TestImageMagicnum = DataSet::DataSet::ReverseInt(TestImageMagicnum);
    TestLabelsnum = DataSet::ReverseInt(TestLabelsnum);
    for (int i = 0; i < TrainLabelsnum; i++)
    {
        unsigned char label = 0;
        TrainLabelFile.read((char *)&label, sizeof(label));
        Trainlabels.push_back((double)label);
    }
    for (int i = 0; i < TestLabelsnum; i++)
    {
        unsigned char label = 0;
        TestLabelFile.read((char *)&label, sizeof(label));
        TestLabels.push_back((double)label);
    }
}

void DataSet::LoadEMnist()
{
    DataSet::preparePath();
    DataSet::readHeader();
    DataSet::readImages();
    DataSet::readLabels();
    TrainImageFile.close();
    TrainLabelFile.close();
    TestImageFile.close();
    TestLabelFile.close();
}

vector<vector<double,gc_allocator<double>>,gc_allocator<vector<double,gc_allocator<double>>>> DataSet::getTrainImages()
{
    return TrainImages;
}

vector<vector<double,gc_allocator<double>>,gc_allocator<vector<double,gc_allocator<double>>>> DataSet::getTestImages()
{
    return TestImages;
}

vector<int,gc_allocator<int>> DataSet::getTarinLabels()
{
    return Trainlabels;
}

vector<int,gc_allocator<int>> DataSet::getTestLabels()
{
    return TestLabels;
}
