//
//  main.cpp
//  week5_practice3
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

int foo(){
    i = 3;
    A ob;
    return i;
}

int &foo2(){
    i = 3;
    A ob;
    return i;
}

int main(int argc, const char * argv[]) {
    
    cout << foo() << endl;
    cout << foo2() << endl;
    
    return 0;
}
