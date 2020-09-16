//
//  main.cpp
//  training_01
//
//  Created by 전병민 on 2020/09/14.
//

#include <iostream>

class SetValue {
private:
    int x, y;
public:
    SetValue() { // SetValue 생성자 - x, y 값 초기화
        x = 0;
        y = 0;
    }
    void setX(int a);
    void setY(int b);
    int getX();
    int getY();
};

void SetValue::setX(int a){
    x = a;
};

void SetValue::setY(int b){
    y = b;
};

int SetValue::getX(){
    return x;
};

int SetValue::getY(){
    return y;
};

int main(int argc, const char * argv[]) {
    SetValue obj;
    
    obj.setX(33);
    obj.setY(44);
    
    std::cout<<"X = "<<obj.getX()<<" ,Y = "<<obj.getY()<<std::endl;
    return 0;
}
