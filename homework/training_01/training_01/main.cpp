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
    void setX(int a);
    void setY(int b);
};

void SetValue::setX(int a){
    x = a;
};

void SetValue::setY(int b){
    y = b;
};

int main(int argc, const char * argv[]) {
    SetValue obj;
    
    obj.setX(33);
    obj.setY(44);
    
    std::cout<<"X = "<<obj.x<<" ,Y = "<<obj.y<<std::endl;
    return 0;
}
