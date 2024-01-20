#include "include/tools.h"
#include <cmath>
#include <list>
using namespace std;

auto getL(int index,list<> l){
	double counter = 0;
	double value;
	try{
		if(index > l.size() || l == null)
			throw 0;
		for(double i:l){
			if(counter == index)
				value = i;
			counter++;
		}
		return value;
	}catch(int* s){
		cout<<"索引大于列表或列表为空";
		exit();
	}
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

