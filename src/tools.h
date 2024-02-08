#ifndef TOOLS_H
#define TOOLS_H

#include <list>
#include <cmath>
#include <variant>
#include <iostream>
#include <type_traits>
using namespace std;
enum LType {input,hidden,output};
enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};


template <typename T>
auto etL(int index,list<T> l) ->typename::std::remove_reference<decltype(l.front())>::type{
    int counter = 0;
	try{
		if(index > l.size() || l.empty())
			throw 1;
		for(auto i:l){
			if(counter == index){
				return i;
			}
			counter++;
		}
		return 0;
	}catch(int s){
		cout<<"索引大于列表或列表为空";
		exit(s);
	}
}

template <typename T>
std::variant<double,Neuron> getDL(int index,list<T> l,int counts) ->decltype(l.front()){
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
	}catch(int s){
		cout<<"索引过大或list为空";
		exit(s);
	}
}

double Linear(double sk,double sb,double input);
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif
