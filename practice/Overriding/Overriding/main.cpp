//
//  main.cpp
//  Overriding
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>

using namespace std;

class base
{
public:
    void output()
    {
        cout << "Its Base Class : " << endl;
    }
};

class derived: public base
{
public:
    void output()
    {
        cout << "Its Derived Class : " << endl;
    }
};

int main(int argc, const char * argv[]) {
    base parent;
    derived child;
    
    parent.output();
    cout << endl;
    child.output();
    return 0;
}
