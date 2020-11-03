//
//  main.cpp
//  week9_practice01
//
//  Created by 전병민 on 2020/11/03.
//

#include <iostream>

class Base {
public:
    void func_1() {};
protected:
    void func_2(){
    
    };
private:
    int x_;
};

class Derived : protected Base {
public:
    void func_3(){
        func_1();
        func_2();
    }
};

int main(int argc, const char * argv[]) {
    Derived d;
    d.func_3();
    d.func_1(); // Error
    /*
     Derived 클래스는 Base 클래스를 protected로 상속받고 있기 때문이다.
     즉, Derived가 아닌 클래스에서는 Base함수의 멤버 변수에 접근하지 못한다.
     당연히 Base에서 x_는 private이기 때문에 상속받았다 하더라도
     Derived 클래스에서 사용하지 못한다.
     */
}
