#include "NeuralNet.h"

NeuralNet::~NeuralNet()
{
    vector<vector<double>>().swap(TrainImageData);
    vector<vector<double>>().swap(TestImageData);
    vector<double>().swap(TrainLabelData);
    vector<double>().swap(TestLabelData);
    vector<Layer>().swap(hiddenLayers);
    vector<ActivateFunction>().swap(ahac);
    vector<double>().swap(inputs);
    vector<double>().swap(targets);
    vector<double>().swap(outputs);
}

NeuralNet::NeuralNet(const int Nnum_hidden_layers, const int Nnum_output_layer, const int num_inputNeurons, const vector<int> &num_hiddenNeurons, const int num_outputNeurons, const vector<ActivateFunction> &ahac, const ActivateFunction &oac)
{
    GC_init();
    num_hidden_layers = Nnum_hidden_layers;
    num_output_layer = Nnum_output_layer;
    inputLayer = Layer(input, num_inputNeurons, null);
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
    for (int epoch = 0; epoch < maxepoch; epoch++)
    {
        for (int i = 0; i < TrainImageData.size(); i++)
        {
            NeuralNet::setInputs(TrainImageData[i]);
            NeuralNet::forwardPropagation();
            NeuralNet::backwardPropagation(i);
            if (PrintCurrentBatchAndEpoch)
            {
                cout << "Current epoch:" << epoch << " Current batch:" << i << endl;
            }
            if (PrintTrainLoss)
            {
                cout << "Current epoch:" << epoch << " " << "Current batch:" << i << " Loss:" << RawLoss.x() << endl;
            }
        }
        Accuracy = NeuralNet::Test();
        if (PrintTestAccuracy)
        {
            cout << "Current epoch:" << epoch << "" << "Accuracy:" << Accuracy << endl;
        }

        if (Accuracy >= 0.85 || epoch == maxepoch)
        {
            break;
        }
    }
}

double NeuralNet::Test()
{
    int CorrectTimes;
    FDouble loss;
    for (int i = 0; i < TestImageData.size(); i++)
    {
        NeuralNet::predict(TestImageData[i]);
        loss = NeuralNet::CCE(outputs, TestLabelData[i]);
        if (loss.x() <= 0.1)
        {
            CorrectTimes++;
        }
    }
    return CorrectTimes / TestLabelData.size();
}

void NeuralNet::predict(const vector<double> &inputs)
{
    inputLayer.setInput(inputs);
    if (num_hidden_layers != 0)
    {
        hiddenLayers[0].setInputs(inputLayer.getLOutputs());
        for (int i = 1; i < num_hidden_layers; i++)
        {
            hiddenLayers[i].setInputs(hiddenLayers[i - 1].getLOutputs());
        }

        if (num_output_layer != 0)
        {
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

ActivateFunction NeuralNet::getHiddenLayerAcFunc(const int id)
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

bool NeuralNet::getPrintCurrentBatchAndEpoch()
{
    return PrintCurrentBatchAndEpoch;
}

void NeuralNet::setLearningRate(const double nlearningRate)
{
    learningRate = nlearningRate;
}

void NeuralNet::setMaxEpoch(const int nepoch)
{
    maxepoch = nepoch;
}

void NeuralNet::setInputLayerAcFunc(const ActivateFunction &niac)
{
    inputLayer.setActivateFunction(niac);
}

void NeuralNet::setAllHiddenLayerAcFunc(const vector<ActivateFunction> &nahac)
{
    int counter = 0;
    for (auto i : hiddenLayers)
    {
        i.setActivateFunction(nahac[counter]);
        counter++;
    }
}

void NeuralNet::setHiddenLayerAcFunc(const int id, const ActivateFunction &nhac)
{
    hiddenLayers[id].setActivateFunction(nhac);
}

void NeuralNet::setOutputLayerAcFunc(const ActivateFunction &noac)
{
    outputLayer.setActivateFunction(noac);
}

void NeuralNet::setInputs(const vector<double> &ninputs)
{
    inputs = ninputs;
    inputLayer.setInput(ninputs);
}

void NeuralNet::setTargets(const vector<double> &ntargets)
{
    targets = ntargets;
}

void NeuralNet::setData(DataSet &set)
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

void NeuralNet::setPrintCurrentBatchAndEpoch(const bool adjustment)
{
    PrintCurrentBatchAndEpoch = adjustment;
}

double NeuralNet::CCE(const vector<double> output,int target){
    vector<double> oh(output.size());
    for(int i=0;i<output.size();i++){
        if(i == target){
            oh[i] = 1;
        }else{
            oh[i] = 0;
        }
    }
    double sum;
    for(int i=0;i<output.size();i++){
        sum += oh[i]*log(output[i]);
    }
    return -sum;
}

void NeuralNet::forwardPropagation()
{
    if (num_hidden_layers != 0)
    {
        hiddenLayers[0].setInputs(inputLayer.getLOutputs());
        for (int i = 1; i < num_hidden_layers; i++)
        {
            hiddenLayers[i].setInputs(hiddenLayers[i - 1].getLOutputs());
        }

        if (num_output_layer != 0)
        {
            outputLayer.setInputs(hiddenLayers[num_hidden_layers - 1].getLOutputs());
        }
    }
    outputs = Softmax(outputLayer.getLOutputs());
}

void NeuralNet::backwardPropagation(const int current_batch)
{
    RawLoss = NeuralNet::CCE(NeuralNet::getOuputs(),TrainLabelData[current_batch]);
    for (auto i : inputLayer.getLWeights())
    {
        for (auto j : i)
        {
            double delta = RawLoss.diff(j, 0);
            j -= learningRate * delta;
        }
    }
    for (auto i : inputLayer.getBiases())
    {
        double delta = RawLoss.diff(i, 0);
        i -= learningRate * delta;
    }
    if (num_hidden_layers != 0)
    {
        for (auto i : hiddenLayers)
        {
            for (auto j : i.getBiases())
            {
                double delta = RawLoss.diff(j, 0);
                j -= learningRate * delta;
            }
        }
    }
    if (num_hidden_layers != 0)
    {
        for (auto i : hiddenLayers)
        {
            for (auto j : i.getLWeights())
            {
                for (auto k : j)
                {
                    double delta = RawLoss.diff(k, 0);
                    k -= learningRate * delta;
                }
            }
        }
    }
    if (num_output_layer != 0)
    {
        for (auto i : outputLayer.getBiases())
        {
            double delta = RawLoss.diff(i, 0);
            i -= learningRate * delta;
        }
    }
    if (num_output_layer != 0)
    {
        for (auto i : outputLayer.getLWeights())
        {
            for (auto j : i)
            {
                double delta = RawLoss.diff(j, 0);
                j -= learningRate * delta;
            }
        }
    }
}

vector<FDouble> NeuralNet::convert(const vector<double> &inputs)
{
    vector<FDouble> OPs;
    for (auto i : inputs)
    {
        OPs.push_back(FDouble(i));
    }
    return OPs;
}
