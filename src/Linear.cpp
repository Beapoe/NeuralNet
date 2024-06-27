#include "Linear.h"
#include <algorithm>
using namespace std;

AType toCompare;
bool Linear::Adjust(Args arg)
{
    return arg.type == toCompare;
}
double Linear::execute(Arguements args){
    vector<int> indexs;
    if (args.type == linear)
    {
        AType need1 = k;
        AType need2 = b;
        AType need3 = i;
        vector<AType> needs = {need1, need2, need3};
        int counter = 0;
        for (auto i : needs)
        {
            toCompare = i;
            Linear obj;
            auto it = find_if(args.arguemnts.begin(), args.arguemnts.end(), AdjustFunctor(obj));
            bool condition = it == args.arguemnts.end();
            if (condition == false)
            {
                indexs.push_back(distance(args.arguemnts.begin(), it));
            }
        }
        double k = args.arguemnts[indexs[0]].value;
        double b = args.arguemnts[indexs[1]].value;
        double input = args.arguemnts[indexs[2]].value;
        return k * input + b;
    }
    else
    {
        cout << "传入参数有误，非线性激活函数" << endl;
        exit(1);
    }
}