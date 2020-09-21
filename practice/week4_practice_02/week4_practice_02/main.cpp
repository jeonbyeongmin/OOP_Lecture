//
//  main.cpp
//  week4_practice_02
//
//  Created by 전병민 on 2020/09/21.
//

#include <iostream>

void increment(int x)
{
    ++x;
}

int main(int argc, const char * argv[]) {
    int x = 55;
    std::cout <<"Before increment : " << x << std::endl;
    increment(x);
    std::cout<<"Ater increment : " << x << std::endl;//값이 변경되지 않음.
    return 0;
}
