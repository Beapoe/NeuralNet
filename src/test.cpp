#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double CCE(vector<double> output,int target){
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
vector<double> Softmax(vector<double> raw){
    vector<double> pro(raw.size());
    double denominator;
    double e = exp(1);
    for(int i=0;i<raw.size();i++){
        denominator += pow(e,raw[i]);
    }
    for(int i=0;i<raw.size();i++){
        pro[i] = pow(e,raw[i])/denominator;
    }
    return pro;
}

int main(){
    double sum;
    vector<double> data = {5.497394,9.4425864,9.9136116,3.187491};
    vector<double> prodata = Softmax(data);
    double loss = CCE(prodata,3);
    cout<<"prodata:"<<endl;
    for(auto i:prodata){
        cout<<i<<endl;
        sum += i;
    }
    cout<<"prodata sum:"<<sum<<endl;
    cout<<"loss:"<<loss<<endl;
    return 0;
}
