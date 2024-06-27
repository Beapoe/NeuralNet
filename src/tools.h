#ifndef TOOLS_H
#define TOOLS_H

#include <list>
#include <iostream>
#include <cmath>

using namespace std;
enum LType {input,hidden,output};
enum AType {i,k,b,v};
enum ActivateFunction {linear,sigmoid,hyperTan,hardThreshold};

template<typename T>
auto getContent(list<T> l,int index){
	auto it = l.begin();
	advance(it,index);
	return *it;
}
double HyperTan(double input);
double Sigmoid(double input);
double HardThreshold(double input);
#endif