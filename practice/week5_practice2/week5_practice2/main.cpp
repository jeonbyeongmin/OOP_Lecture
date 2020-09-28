//
//  main.cpp
//  week5_practice2
//
//  Created by 전병민 on 2020/09/28.
//

#include <iostream>

class Animal {
public:
    char* name;
    int age;
    Animal(int age_, const char* name_){
        age = age_;
        name = new char[strlen(name_)+1];
        strcpy(name, name_);
    }
    Animal(Animal& a){ // deep copy
        age = a.age;
        name = new char[strlen(a.name)+1];
        strcpy(name, a.name);
    }
//    Animal(Animal& a){ // shallow copy
//        age = a.age;
//        name = a.name;
//    }
    
    void changeName(const char* newName){
        strcpy(name, newName);
    }
    void printAnimal(){
        std::cout <<"name : " <<name<<", age : "<<age << std::endl;
    }
};



int main(int argc, const char * argv[]) {
    Animal A(10, "Jenny");
    Animal B = A;
    A.age = 22;
    A.changeName("Brown");
    
    A.printAnimal();
    B.printAnimal();
    
    
    return 0;
}
