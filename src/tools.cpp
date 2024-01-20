#include "include/tools.h"
#include <cmath>
#include <list>
using namespace std;

double getDL(int index,list<double> l){
	double counter = 0;
	double value;
	for(double i:l){
		if(counter == index)
			value = i;
		counter++;
	}
	return value;
}
double Linear(double sk,double sb,double input){
	return input*sk+sb;
}

double HyperTan(double input){
	return (std::exp(input)-std::exp(-input))/2;
}

double Sigmoid(double input){
	return 1/(1+std::exp(-input));
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

