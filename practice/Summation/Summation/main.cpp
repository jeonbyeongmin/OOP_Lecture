//
//  main.cpp
//  Summation
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>
using namespace std;

class Summation
{
private:
    //private variables
    int a, b, c;
    
public:
    void sum(int x, int y)
    {
        a = x;
        b = y;
        c = a + b;
        cout << "Sum of the two number is : " << c << endl;
    }

};

int main(int argc, const char * argv[])
{
    Summation s;
    s.sum(5, 4);
    return 0;
}
