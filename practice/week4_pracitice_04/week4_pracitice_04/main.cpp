//
//  main.cpp
//  week4_pracitice_04
//
//  Created by 전병민 on 2020/09/21.
//
void increment(int &x)
{
    ++x;
}
#include <iostream>

int main(int argc, const char * argv[]) {
    int x = 55;
    std::cout<<"Before increment : " << x << std::endl;
    increment(x);
    std::cout<<"Before increment : " << x << std::endl;
    return 0;
}
