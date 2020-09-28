//
//  main.cpp
//  week5_practice01
//
//  Created by 전병민 on 2020/09/28.
//

#include <iostream>

class Animal {
public:
    Animal() {
        
    }
    Animal(int numberOfLeg){
        this->numberOfLeg = numberOfLeg;
    }
    
private:
    int numberOfLeg;
};

int main(int argc, const char * argv[]) {
    Animal a; // 디폴트 생성자 암시적 호출
    return 0;
}
