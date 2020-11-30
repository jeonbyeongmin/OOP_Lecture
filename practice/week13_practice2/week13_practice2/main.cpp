//
//  main.cpp
//  week13_practice2
//
//  Created by 전병민 on 2020/11/24.
//

#include <iostream>
template<typename T>

void swapXX(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
    
}
template<>
void swapXX(std::string& a, std::string& b){
    std:: string temp = a;
}


int main(int argc, const char * argv[]) {
    
    std::string a = "world";
    std::string b = "Hello";
    
    swapXX(a, b);
    
    std::cout << "a : " << a << ", b : "<< b << std::endl;
    
    return 0;
}
