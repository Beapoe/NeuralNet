#ifndef LINEAR_H_
#define LINEAR_H_
#include "ActivationFunction.h"
#include <algorithm>


class Linear:public ActivationFunction{
    public:
        bool Adjust(Args arg);
        double execute(Arguements args) override;
        struct AdjustFunctor
        {
            Linear& linearobj;
            explicit AdjustFunctor(Linear& ):linearobj(linearobj){}
            bool operator()(const auto& element) const{
                return (linearobj.*&Linear::Adjust)(element);
            }
        };
        
};

#endif