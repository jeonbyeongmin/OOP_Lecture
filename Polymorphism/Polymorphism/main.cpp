//
//  main.cpp
//  Polymorphism --> Overloading
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>

using namespace std;

class Math
{
    
public:
    void result(int x, int y)
    {
        cout << "The result is : " << x+y << endl;
    }
    void result(int x, int y, int z)
    {
        cout << "The reuslt is : " << x+y+z << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Math m;
    m.result(4, 9);
    m.result(3, 6, 10);
    
    
    return 0;
}
