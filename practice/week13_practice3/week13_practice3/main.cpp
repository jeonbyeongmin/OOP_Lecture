//
//  main.cpp
//  week13_practice3
//
//  Created by 전병민 on 2020/11/24.
//

#include <iostream>

template<typename T>
T min(T x, T y) {
    return x < y ? x : y;
}
int main() {
    int x = 3;
    int y = 2;
    double d = 2.1;
    double e = 3.3;
    std::cout << "min(x,y) : " << min(x, y) << ", min(d,e) : " << min(d, e) << ", min(d,x) : " << min<double>(d, x) << std::endl; // why error?

    return 0;
}
