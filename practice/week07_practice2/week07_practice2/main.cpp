//
//  main.cpp
//  week07_practice2
//
//  Created by 전병민 on 2020/10/12.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> vec;
    vec.push_back(11);
    vec.push_back(22);
    vec.push_back(33);
    vec.push_back(44);
    
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        if (*itr == 22) {
            vec.erase(itr);
        }
    }
    
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << "Vector element " << *itr << std::endl;
    }
    
    return 0;
}
