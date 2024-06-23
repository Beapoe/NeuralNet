#include <list>
#include <variant>
#include <iostream>
#include <cmath>
using namespace std;

double Linear(double sk,double sb,double input){
	return input*sk+sb;
}

double HyperTan(double input){
	return (exp(input)-exp(-input))/2;
}

double Sigmoid(double input){
	return 1/(1+exp(-input));
}

double HardThreshold(double input){
	double value;
	if(input>1){
		value = input;
	}
	if(input<1){
		value = 0;
	}
	return value;
}

