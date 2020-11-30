//
//  main.cpp
//  week13_practice5
//
//  Created by 전병민 on 2020/11/24.
//

template<typename T>
class PairXX {
public:
    PairXX(T x = 0.0, T y = 0.0) : x_(x), y_(y) {}
    T returnX() const { return x_; }
    T returnY() const { return y_; }
private:
    T x_, y_;
};

int main() {
    PairXX<double> pd;
    PairXX<float> pf;
    return 0;
}
