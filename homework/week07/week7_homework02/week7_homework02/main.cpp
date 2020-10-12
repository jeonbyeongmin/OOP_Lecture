//
//  main.cpp
//  week7_homework02
//
//  Created by 전병민 on 2020/10/12.
//
//
#include <iostream>

bool funcA() {
    int c;
    std::cin >> c;
    if (c < 10) //Let's assume this is exception
        throw std::out_of_range("Invalid Input!!");
    return true;
}
int main() {
    try {
        funcA();
    } catch (std::out_of_range& e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
