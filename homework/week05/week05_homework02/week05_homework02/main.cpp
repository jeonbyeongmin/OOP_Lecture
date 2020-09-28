//
//  main.cpp
//  week05_homework02
//
//  Created by 전병민 on 2020/09/28.
//

#include <iostream>

using namespace std;

int i;

class A {
public:
    ~A() {
        i = 10;
    }
};

int foo() {
    i = 3;
    A ob;
    return i;
}

int main(int argc, const char * argv[]) {
    cout << foo() << endl;
    cout << i << endl;
    return 0;
}
