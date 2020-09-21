//
//  main.cpp
//  week4_practice_01
//
//  Created by 전병민 on 2020/09/21.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    std::string s;
    std::cout << "문자를 입력하세요. (100자 이내)." << std::endl;
    std::cin >> s;
    std::cout << "입력된 문자는 " << s << "입니다." << std::endl;
    
    system("puase");
    return 0;
}
