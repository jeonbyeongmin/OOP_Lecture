//
//  main.cpp
//  week04_homework_02
//
//  Created by 전병민 on 2020/09/22.
//

#include <iostream>
void swap(int &first, int &second)
{
    
    int temp = first;
    first = second;
    second = temp;
}

int main(int argc, const char * argv[]) {
    int a = 2;
    int b = 3;
    swap(a, b);

    std::cout << "a = " << a << ", " << "b = " << b << std::endl;
    return 0;
}
