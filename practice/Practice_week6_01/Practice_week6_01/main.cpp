//
//  main.cpp
//  Practice_week6_01
//
//  Created by 전병민 on 2020/10/07.
//

#include <iostream>

class My_cat {
    int age;
    char* name;
    int weight;
public:
    My_cat();
    My_cat(int x, const char* name);
    My_cat(const My_cat& cat); // 복사생성자
    ~My_cat();
    static int number_of_cats;
    
    void show_status() const;
};

int My_cat::number_of_cats = 0;
My_cat::My_cat() : age(20), name(NULL), weight(10){
    number_of_cats++;
} // 초기화 리스트 사용

My_cat::My_cat(int x, const char* cat_name) :weight(10) {
    age = x;
    name = new char[strlen(cat_name)+1];
    number_of_cats++;
    strcpy(name, cat_name);
}

My_cat::My_cat(const My_cat& cat) : weight(10){ // 깊은 복사
    std::cout << "Copy constructor invocation !" << std::endl;
    age = cat.age;
    name = new char[strlen(cat.name)+1];
    number_of_cats++;
    strcpy(name, cat.name);
}

My_cat::~My_cat() { // 소멸자
    if(name) delete [] name;
    number_of_cats--;
}

void My_cat::show_status() const {
    std::cout << "My Cat Name :: " << name << std::endl;
    std::cout << "Age :: " << age << std::endl;
    std::cout << "Weight :: " << weight << std::endl;
    std::cout << "Current Number Of Cats :: " << number_of_cats << std::endl;
}


int main(int argc, const char * argv[]) {
    My_cat cat1(3, "Nabi");
    cat1.show_status();
    
    My_cat cat2 = cat1;
    cat2.show_status();
    
    My_cat cat3(4, "ToTo");
    cat3.show_status();
    
    getchar();
    return 0;
}
