#include <list>
#include <variant>
#include <iostream>
#include <cmath>
#include "Neuron.h"
using namespace std;

template <typename T>
auto getL(int index,list<T> l) ->decltype(l.front()){
 int counter = 0;
	double value;
	 try{
		 if(index > l.size() || l.empty())
			 throw 1;
		 for(double i:l){
			if(counter == index){
				value = i;
				break;
			}
			counter++;
		}
		return value;
	}catch(int* s){
		cout<<"索引大于列表或列表为空";
		exit(s);
	}
}

template <typename T>
std::variant<double,Neuron> getDL(int index,list<T> l,list<int> counts){
	try{
		if(index<l.size() && !l.empty() && !counts.empty()){
			list<T> tl1,tl2;
			for(int i=0;i<counts.size();i++){
				if(i == 0)
					tl1 = getL(getL(i,counts),l).copy();
				if(i == counts.size()-1){
					if(i%2 == 0)
						return getL(getL(i,counts),tl2);
					if(i%2 !=0)
						return getL(getL(i,counts),tl1);
				}			
				if(i%2 == 0)
					tl1 = getL(getL(i,counts),tl2);
				if(i%2 != 0)
					tl2 = getL(getL(i,counts),tl1);
			}
		}else{
			throw 1;
		}
	}catch(int* s){
		cout<<"索引过大或list为空";
		exit(s);
	}
}

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

