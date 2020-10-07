//
//  main.cpp
//  week6_homework02_2
//
//  Created by 전병민 on 2020/10/07.
//
#include <iostream>
#include <string>

class Animal {
private:

public:
    
    std::string name;
    Animal() {};
    Animal(std::string name) : name(name) {};

    void showName() {
        std::cout << "Name is " << name << std::endl;
    }

    Animal& operator+(const Animal &a) {
        name += a.name;
        return *this;
    }
};

int main() {
    Animal cat("Nabi");
    cat.showName();
    Animal dog("Jindo");
    dog.showName();

    Animal catDog = dog + cat;
    catDog.showName();
    dog.showName();

    getchar();
    return 0;
}
