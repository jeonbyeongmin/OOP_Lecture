//
//  main.cpp
//  week13_homework1
//
//  Created by 전병민 on 2020/11/30.
//

#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    for (auto sorted = first; first != last; last = sorted) {
        sorted = first;
        for (auto cur = first, prev = first; ++cur != last; ++prev) {
            if (comp(*cur, *prev)) {
                std::iter_swap(cur, prev);
                sorted = cur;
            }
        }
    }
}
struct compLess {
    bool operator()(int a, int b) {
        return a < b;
    }
};

struct compGreater {
    bool operator()(int a, int b) {
        return a > b;
    }
};


int main() {
    std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

    std::cout << "오름차순 정렬" << std::endl;
    
    compLess compLess; //Functor ª˝º∫
    bubble_sort(values.begin(), values.end(), compLess); // compLess라는 functor에 의해 오름차순 정렬

    for (auto it = values.begin(); it != values.end(); ++it) { // 수열 출력
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "내림차순 정렬" << std::endl;
    compGreater compGreater;
    bubble_sort(values.begin(), values.end(), compGreater); // compGreater라는 functor에 의해 내림차순 정렬

    for (auto it = values.begin(); it != values.end(); ++it) { // 수열 출력
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    getchar();
}
