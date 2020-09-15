//
//  main.cpp
//  training_01
//
//  Created by 전병민 on 2020/09/14.
//

#include <iostream>

class SetValue {
public:
    int x, y;
    void setValue(int a, int b);
};

void SetValue::setValue(int a, int b){
    x = a;
    y = b;
};

int main(int argc, const char * argv[]) {
    SetValue obj;
    obj.setValue(33, 44);
    
    std::cout<<"X = "<<obj.x<<" ,Y = "<<obj.y<<std::endl;
    return 0;
}

