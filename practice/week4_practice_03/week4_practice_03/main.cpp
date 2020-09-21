//
//  main.cpp
//  week4_practice_03
//
//  Created by 전병민 on 2020/09/21.
//
//  C++ Pointer


#include <iostream>
void increment(int *x)
{
    ++ *x;
}
int main(int argc, const char * argv[]) {
    int x = 55;
    std::cout<<"Before increment : "<<x<<std::endl;
    increment(&x);
    std::cout<<"Before increment : "<<x<<std::endl;
    return 0;
}
