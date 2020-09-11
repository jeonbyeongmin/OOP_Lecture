//
//  main.cpp
//  Inheritance
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>

using namespace std;

class TWOD_Shape
{
public:
    double width;
    double height;
    
    void showDim()
    {
        cout << "Width and height are " << width << " and " << height << endl;
    }
};

class Triangle : public TWOD_Shape
{
public:
    double area()
    {
        return width * height / 2;
    }
};

int main(int argc, const char * argv[]) {
    
    Triangle tri;
    
    tri.width = 20;
    tri.height = 10;
    
    tri.showDim();
    cout << "area is " << tri.area() << endl;
    
    return 0;
}
