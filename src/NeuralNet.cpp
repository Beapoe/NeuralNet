#include "NeuralNet.h"

NeuralNet::NeuralNet(int Nnum_hidden_layers, int Nnum_output_layer, int num_inputNeurons, vector<int> num_hiddenNeurons, int num_outputNeurons, vector<ActivateFunction> ahac, ActivateFunction oac)
{
    num_hidden_layers = Nnum_hidden_layers;
    num_output_layer = Nnum_output_layer;
    inputLayer = Layer(input,num_inputNeurons,null);
    if (Nnum_hidden_layers != 0)
    {
        for (int i = 0; i < Nnum_hidden_layers; i++)
        {
            hiddenLayers.push_back(Layer(hidden, num_hiddenNeurons[i], ahac[i]));
        }
        hiddenLayers[0].setNumInputs(inputLayer.getNumNeuronsInLayer());
        hiddenLayers[0].init(inputLayer.getNumNeuronsInLayer());
        for (int i = 1; i < Nnum_hidden_layers; i++)
        {
            hiddenLayers[i].setNumInputs(hiddenLayers[i - 1].getNumNeuronsInLayer());
            hiddenLayers[i].init(hiddenLayers[i - 1].getNumNeuronsInLayer());
        }
    }
    if (Nnum_output_layer != 0)
    {
        outputLayer = Layer(output, num_outputNeurons, oac);
        outputLayer.setNumInputs(hiddenLayers[Nnum_hidden_layers - 1].getNumNeuronsInLayer());
        outputLayer.init(hiddenLayers[Nnum_hidden_layers - 1].getNumNeuronsInLayer());
    }
}

void NeuralNet::train()
{
double Accuracy;
NeuralNet::setTargets(TrainLabelData);
for(int epoch=0; epoch<maxepoch; epoch++){
    for(int i=0;i<TrainImageData.size();i++){
        NeuralNet::setInputs(TrainImageData[i]);
        NeuralNet::forwardPropagation();
        NeuralNet::backwardPropagation(i);
    }
    Accuracy = NeuralNet::Test();
    if(PrintTestAccuracy == true){
        cout<<"Current epoch:"<<epoch<<""<<"Accuracy:"<<Accuracy<<endl;
    }
    if(PrintTrainLoss == true){
        cout<<"Current epoch:"<<epoch<<""<<"Loss:"<<loss.x()<<endl;
    }
    if(Accuracy >= 0.85 || epoch == maxepoch){
        break;
    }
}
}

double NeuralNet::Test()
{
    int CorrectTimes;
    FDouble loss;
    for(int i=0;i<TestImageData.size();i++){
        NeuralNet::predict(TestImageData[i]);
        loss = NeuralNet::CCE(NeuralNet::convert(outputs),TestLabelData[i]);
        if(loss <= 0.1){CorrectTimes++;}
    }
    return CorrectTimes/TestLabelData.size();
}

void NeuralNet::predict(vector<double> inputs)
{
    inputLayer.setInput(inputs);
    if(num_hidden_layers != 0){
        hiddenLayers[0].setInputs(inputLayer.getLOutputs());
        for(int i = 1; i < num_hidden_layers; i++){
            hiddenLayers[i].setInputs(hiddenLayers[i - 1].getLOutputs());
        }

    if(num_output_layer != 0){
        outputLayer.setInputs(hiddenLayers[num_hidden_layers - 1].getLOutputs());
    }
        }
        outputs = Softmax(outputLayer.getLOutputs());
}

void NeuralNet::save()
{
}

void NeuralNet::load()
{
}

double NeuralNet::getLearningRate()
{
    return learningRate;
}

int NeuralNet::getMaxEpoch()
{
    return maxepoch;
}

ActivateFunction NeuralNet::getInputLayerAcFunc()
{
    return iac;
}

vector<ActivateFunction> NeuralNet::getAllHiddenLayerAcFunc()
{
    return ahac;
}

ActivateFunction NeuralNet::getHiddenLayerAcFunc(int id)
{
    return hiddenLayers[id].getActivateFunction();
}

ActivateFunction NeuralNet::getOutputLayerAcFunc()
{
    return oac;
}

vector<double> NeuralNet::getInputs()
{
    return inputs;
}

vector<double> NeuralNet::getOuputs()
{
    return outputs;
}

vector<double> NeuralNet::getTargets()
{
    return targets;
}

vector<vector<double>> NeuralNet::getTrainImaageData()
{
    return TrainImageData;
}

vector<vector<double>> NeuralNet::getTestImageData()
{
    return TestImageData;
}

vector<double> NeuralNet::getTrainLabelData()
{
    return TrainLabelData;
}

vector<double> NeuralNet::getTestLabelData()
{
    return TestLabelData;
}

bool NeuralNet::getPrintTestAccuracy()
{
    return PrintTestAccuracy;
}

bool NeuralNet::getPrintTrainLoss()
{
    return PrintTrainLoss;
}

void NeuralNet::setLearningRate(double nlearningRate)
{
    learningRate = nlearningRate;
}

void NeuralNet::setMaxEpoch(int nepoch)
{
    maxepoch = nepoch;
}

void NeuralNet::setInputLayerAcFunc(ActivateFunction niac)
{
    inputLayer.setActivateFunction(niac);
}

void NeuralNet::setAllHiddenLayerAcFunc(vector<ActivateFunction> nahac)
{
    int counter = 0;
    for(auto i:hiddenLayers){
        i.setActivateFunction(nahac[counter]);
        counter++;
    }
}

void NeuralNet::setHiddenLayerAcFunc(int id, ActivateFunction nhac)
{
    hiddenLayers[id].setActivateFunction(nhac);
}

void NeuralNet::setOutputLayerAcFunc(ActivateFunction noac)
{
    outputLayer.setActivateFunction(noac);
}

void NeuralNet::setInputs(vector<double> ninputs)
{
    inputs = ninputs;
    inputLayer.setInput(inputs);
}

void NeuralNet::setTargets(vector<double> ntargets)
{
    targets = ntargets;
}

void NeuralNet::setData(DataSet& set)
{
    TrainImageData = set.getTrainImages();
    TestImageData = set.getTestImages();
    TrainLabelData = set.getTarinLabels();
    TestLabelData = set.getTestLabels();
}

void NeuralNet::setPrintTestAccuracy(bool adjustment)
{
    PrintTestAccuracy = adjustment;
}

void NeuralNet::setPrintTrainLoss(bool adjustment)
{
    PrintTrainLoss = adjustment;
}

FDouble NeuralNet::CCE(vector<FDouble> outputs, FDouble target)
{
    vector<double> OneHotLabel(10, 0);
    if (target >= 0 && target < 10)
    {
        OneHotLabel[target.x()] = 1;
    }
FDouble loss = 0.0;
for(int i=0;i<10;++i){
    if (OneHotLabel[i]==1)
    {
        if(outputs[i]==0.0){
            loss = -log(numeric_limits<double>::min());
        }else{
            loss=-log(outputs[i].x());
        }
    }
}
return loss;
}

void NeuralNet::forwardPropagation()
{
    if(num_hidden_layers != 0){
        hiddenLayers[0].setInputs(inputLayer.getLOutputs());
        for(int i = 1; i < num_hidden_layers; i++){
            hiddenLayers[i].setInputs(hiddenLayers[i - 1].getLOutputs());
        }

    if(num_output_layer != 0){
        outputLayer.setInputs(hiddenLayers[num_hidden_layers - 1].getLOutputs());
    }
        }
        outputs = Softmax(outputLayer.getLOutputs());
        
}

void NeuralNet::backwardPropagation(int current_batch)
{
    loss = NeuralNet::CCE(NeuralNet::convert(NeuralNet::getOuputs()),FDouble(TrainLabelData[current_batch]));
    for (auto i : inputLayer.getLWeights())
    {
        for (auto j : i)
        {
            double delta = loss.diff(j, 0);
            j -= learningRate * delta;
        }
    }
    for(auto i:inputLayer.getBiases()){
        double delta = loss.diff(i, 0);
        i -= learningRate * delta;
    }
    if(num_hidden_layers != 0){
        for(auto i:hiddenLayers){
            for(auto j:i.getBiases()){
                double delta = loss.diff(j, 0);
                j -= learningRate * delta;
            }
        }
    }
    if(num_hidden_layers != 0){
        for(auto i:hiddenLayers){
            for(auto j:i.getLWeights()){
                for(auto k:j){
                    double delta = loss.diff(k, 0);
                    k -= learningRate * delta;
                }
            }
        }
    }
    if(num_output_layer != 0){
        for(auto i:outputLayer.getBiases()){
            double delta = loss.diff(i, 0);
            i -= learningRate * delta;
        }
    }
    if(num_output_layer != 0){
        for(auto i:outputLayer.getLWeights()){
            for(auto j:i){
                double delta = loss.diff(j, 0);
                j -= learningRate * delta;
            }
        }
    }
}

vector<FDouble> NeuralNet::convert(vector<double> inputs)
{
    vector<FDouble> outputs;
    for(auto i:inputs){
        outputs.push_back(FDouble(i));
    }
    return outputs;
}
