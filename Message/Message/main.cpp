//
//  main.cpp
//  Message
//
//  Created by 전병민 on 2020/09/11.
//

#include <iostream>

using namespace std;
class Message
{
    //Private Member
    private:
    string name = "Byeongmin Jeon";
    int age = 23;
    float marks = 95.65;
    
    //Public Members
    public:
    void display()
    {
        // cout : 콘솔 출력 명령어
        // endl : 개행
        cout << name << " is " << age << " year Old: " << endl;
        cout <<"He got "<< marks <<"% marks in his exam : ";
    }
};
int main(int argc, const char * argv[]) {
    
    //Creating Object
    Message msg;
    
    //Calling Class Public Member using Dot Operation
    msg.display();
    
    return 0;
}
