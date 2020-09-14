//
//  main.cpp
//  Addition
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>

using namespace std;

class addition // 1부터 n까지 합을 구하는 class
{
    
private: //Private Members: (data Member)
    int UpperLimit;
    int sum;
    int number;
    
public: //Public Members: (Method)
    addition()
    {
        UpperLimit = 0;
        sum = 0;
        number = 0;
    }
    void showResult(){
        cout << "Enter the Upper Limit to get sum : ";
        cin >> UpperLimit; //cin : input
        
        while (number < UpperLimit) {
            number = number + 1;
            sum = sum + number;
        }
        
        cout << "The sum of first " << UpperLimit << " Number ar : " << sum << endl;
    }
    
};

int main(int argc, const char * argv[]) {
    addition obj;
    obj.showResult();
    
    return 0;
}
