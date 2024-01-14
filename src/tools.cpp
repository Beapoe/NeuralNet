#include "include/tools.h"
#include <cmath>

double Linear(double sk,double sb,double input){
	return input*sk+sb;
}

double HyperTan(double input){
	return (std::exp(input)-std::exp(-input))/2;
}

double Sigmoid(double input){
	return 1/(1+std::exp(-input))
}

double HardThreshold(double input){
	if(input>1){
		return input;
	}
	if(input<1){
		return 0;
	}
}
