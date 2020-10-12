//
//  main.cpp
//  week7_homework01
//
//  Created by 전병민 on 2020/10/12.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class AnyString {
    string anyString;

public:
    AnyString(const std::string& anyString) : anyString(anyString) {}
    string getAnyString() {
        return "Stored String :: " + anyString;
    }
    friend ostream& operator<<(ostream& os, const AnyString& a);
};

ostream& operator<<(ostream& os, const AnyString& a){
    os << a.anyString;
    return os;
}

int main() {
    std::ofstream out("testOveroding.txt");
    AnyString a("Hello, this is operator overloading test!!!");

    std::string output = a.getAnyString();

    out << a << std::endl;

    return 0;
}
