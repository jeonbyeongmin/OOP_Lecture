//
//  main.cpp
//  week05_homework03_1
//
//  Created by 전병민 on 2020/09/28.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>

class Animal {
    
    char* name;
    int age;
    
public:
    Animal(int age_, const char* name_){ // Constructor
        age = age_;
        name = new char[strlen(name_)+1];
        strcpy(name, name_);
    }
    
    Animal(const Animal& a){ // Copy constructor with deep copy
        age = a.age;
        name = new char[strlen(a.name)+1];
        strcpy(name, a.name);
        std::cout << "Copy constructor is invoked!!" << std::endl;
    }
    
    ~Animal(){ // Destructor
        std::cout << "Destructor!!" << std::endl;
        delete [] name;
    }
    
    void changeName(const char* newName){
        strcpy(name, newName);
    }
    
    void printAnimal() {
        std::cout << "Name : " << name << " Age : " << age << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Animal A(10, "Jenny");
    
    A.printAnimal();
    
    std::vector<Animal> vec; // Vector for Animal type
    
    std::cout << "-----1st push-----" << std::endl;
    vec.push_back(A);
    std::cout << "-----2nd push-----" << std::endl;
    vec.push_back(A);
    std::cout << "-----3rd push-----" << std::endl;
    vec.push_back(A);
    std::cout << "-----4th push-----" << std::endl;
    vec.push_back(A);
    std::cout << "-----5th push-----" << std::endl;
    vec.push_back(A);
    
    A.printAnimal();
    vec[0].printAnimal();
    vec[1].printAnimal();
    vec[2].printAnimal();
    vec[3].printAnimal();
    vec[4].printAnimal();
    
    return 0;
}
