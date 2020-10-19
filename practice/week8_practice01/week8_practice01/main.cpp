//
//  main.cpp
//  week8_practice01
//
//  Created by 전병민 on 2020/10/19.
//

#include <iostream>

class GlobalLogger{
private:
    int log_value;
    static GlobalLogger* s_instance;
    GlobalLogger(int v = 0){
        log_value = v;
    }
public:
    int get_log_data(){
        return log_value;
    }
    void set_log_data(int v){
        log_value = v;
    }
    static GlobalLogger* instance(){
        if (s_instance == NULL) {
            s_instance = new GlobalLogger();
        }
        return s_instance;
    }
};

// Default initialization
GlobalLogger* GlobalCla

void Logger_User_A(void){
    // Initialization on first use
    global_Logger_ptr->set_log_data(1);
    std::cout << "Logger_User_A: log_data is " << global_Logger_ptr->get_log_data() << '\n';
}

void Logger_User_B(void){
    if (!global_Logger_ptr)
        global_Logger_ptr = new GlobalLogger;
    global_Logger_ptr->set_log_data(2);
    std::cout << "Logger_User_B: log_data is " << global_Logger_ptr->get_log_data() << '\n';
}

int main(){
    if (!global_Logger_ptr)
        global_Logger_ptr = new GlobalLogger;
    std::cout << "main: log_data is " << global_Logger_ptr->get_log_data() << '\n';
    Logger_User_A();
    Logger_User_B();
}
