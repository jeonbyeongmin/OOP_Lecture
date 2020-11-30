//
//  main.cpp
//  week13_practice01
//
//  Created by 전병민 on 2020/11/24.
//

#include <iostream>


template<typename T>
void swapXX(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}

void swapInt(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void swapFloat(float&a, float&b){
    float temp = a;
    a = b;
    b = temp;
}

int main(int argc, const char * argv[]) {
    int a =3;
    int b =5;
    float c = 4.3;
    float d = 1.2;
    
    swapXX(a, b);
    swapXX(c, d);
    
    std::cout << " a : " << a << " b : " << b << std::endl;
    std::cout << " c : " << c << " d : " << d << std::endl;
    
    
    return 0;
}
