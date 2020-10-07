//
//  main.cpp
//  Practice_week6_02
//
//  Created by 전병민 on 2020/10/07.
//

#include <iostream>
#include <string>

class Animal {
private:
    std::string name;
    
public:
    Animal() {
        
    };
    Animal(std::string name) : name(name) {
        
    };
    void showName(){
        std::cout << "Name is " << name << std::endl;
    }
    
    Animal operator+(const Animal& a){
        Animal temp;
        temp.name = this -> name + a.name;
        return temp;
    };
    
};

int main(int argc, const char * argv[]) {
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
