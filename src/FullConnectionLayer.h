#ifndef FCL_H_
#define FCL_H_

#include <memory>
#include <functional>
#include "matrix.h"

class FullConnectionLayer{
    private:
        std::unique_ptr<double[]> inputs;
        matrix<double> weights;
        std::unique_ptr<double[]> biases;
        std::unique_ptr<double[]> inputs;
        std::function<double(double)> activation;
    public:
        FullConnectionLayer()=default;
        ~FullConnectionLayer()=default;
        void setInputs(std::unique_ptr<double[]> ninputs);
        void setWeights(matrix<double> nweights);
        void setBiases(std::unique_ptr<double[]> nbiases);
        void setActivation(std::function<double(double)> nactivation);
        std::unique_ptr<double[]> getInputs();
        matrix<double> getWeights();
        std::unique_ptr<double[]> getBiases();
        std::function<double(double)> getActivation();
};

#endif
