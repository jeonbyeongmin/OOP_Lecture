//
//  main.cpp
//  week7_practice1
//
//  Created by 전병민 on 2020/10/12.
//

#include <iostream>

class Animal {
public:
    //
protected:
    int age;
    
};

class  bird : public Animal {
private:
    int wing;
    
};

class Cat : public virtual Animal{};
class Dog : public virtual Animal{};

class DogCat : public Cat, public Dog {
public:
    void setAge() {
        age = 10;
        Cat::age = 10;
        
    }
};

int main(int argc, const char * argv[]) {
    DogCat* dat = new DogCat();
    Animal* animal;
    animal = dat;
    animal = static_cast <Cat*>(dat);
    animal = (Cat*)dat;
}
