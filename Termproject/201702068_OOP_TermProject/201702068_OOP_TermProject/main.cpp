#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstring>

using namespace std;

bool isDisit(string str) {
    return atoi(str.c_str()) != 0 && stoi(str) > 0 && to_string(atoi(str.c_str())) == str.c_str();
}
bool validationCheck(string command) {
    return command[1] == '(' && command[command.size() - 1] == ')' && command[2] != ',' && command[command.size() - 2] != ',';
}
vector<string> stringTokenizer(string str, char tokenizer) {
    string str_buff;
    stringstream s(str);
    vector<string> newVector;

    while (getline(s, str_buff, tokenizer)) {
        newVector.push_back(str_buff);
    }
    return newVector;
}
vector<string> linesToWords(vector<string> lines) {
    vector<string> words;
    for (int i = 0; i < lines.size(); i++) {
        vector<string> temp = stringTokenizer(lines[i], ' ');
        for (int j = 0; j < temp.size(); j++) {
            words.push_back(temp[j]);
        }
    }
    return words;
}
vector<string> wordsToLines(vector<string> words) {
    vector<string> lines;
    string line = "";

    for (int i = 0; i < words.size(); i++) {
        string temp;
        if (line == "") {
            temp = words[i];
        }
        else {
            temp = " " + words[i];
        }

        if ((line + temp).size() > 75) {
            lines.push_back(line);
            line = temp.substr(1);
        }
        else if ((line + temp).size() == 75) {
            line += temp;
            lines.push_back(line);
            line = "";
        }
        else {
            line += temp;
        }
    }
    return lines;
}
vector<string> update(vector<string> lines) {
    vector<string> newWords = linesToWords(lines);
    vector<string> newlines = wordsToLines(newWords);
    return newlines;
}
vector<string> fileToVector(string path) {

    ifstream myfile(path);

    if (!myfile.is_open()) {
        cout << "Can't find the file" << endl;
    }

    char alpha;
    string word = "";
    string line = "";
    vector<string> lines;

    while (myfile) {

        alpha = myfile.get();
        if (!myfile.eof()) { // 마지막에 EOF값을 넣지 않기 위해서
            word += alpha;
        }

        if (alpha == ' ' || myfile.eof()) {
            if ((line + word).length() - 1 == 75) {
                line += word;
                lines.push_back(line);
                word = "";
                line = "";

            }
            else if ((line + word).length() - 1 > 75) {
                lines.push_back(line);
                line = word;

                if (myfile.eof()) {
                    lines.push_back(line);
                }
                word = "";

            }
            else {
                line += word;
                if (myfile.eof()) {
                    lines.push_back(line);
                }
                word = "";
            }

        }

    }
    myfile.close();
    return lines;
}
vector<string> parseCommand(string command) {
    string sign_command = "";

    for (int i = 2; i <= command.size() - 2; i++)
    {
        sign_command += command[i];
    }

    vector<string> elements = stringTokenizer(sign_command, ',');

    return elements;
}

class Receiver {
protected:
    static int count;
    static string console;
    static vector<string> lines;

    static int isFirstPage;
    static int isLastPage;

public:
    virtual void execute() = 0;
};

int Receiver::count = 1;
string Receiver::console = "";
vector<string> Receiver::lines;
int Receiver::isFirstPage = 1;  // init page is first page
int Receiver::isLastPage = 0;

// Print Instruction ============================================================================================================
class Print : public Receiver {
public:
    Print(vector<string> lines) {
        this->count = 1;
        this->console = "";
        this->lines = lines;
        this->isFirstPage = 1;
        this->isLastPage = 0;
    }
    void execute() {

        int numberOfLine = 0;

        while (count <= lines.size()) {

            if (numberOfLine == 20) {
                break;
            }

            if (count < 10) {
                cout << " " << count << "| " << lines[count - 1] << endl;
            }
            else {
                cout << count << "| " << lines[count - 1] << endl;
            }
            numberOfLine++;
            count++;
        }

        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << console << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "입력 : ";
    }
};

// Insert Instruction ===========================================================================================================
class Insert : public Receiver {
public:
    Insert(vector<string> elements) {
        this->elements = elements;
    }
    void execute() override {
        insert_target();
    }
private:
    vector<string> elements;
    void insert_target() {
        count = count - 20;

        if (!isDisit(elements[0]) || !isDisit(elements[1])) { // 첫번째 인자가 숫자가 아니라면?
            console = "입력이 올바르지 않습니다. 첫번째와 두번째 인자는 양의 정수여야 합니다.";
        }
        else {
            if (count <= stoi(elements[0]) && stoi(elements[0]) <= count + 19) { // 현재 페이지 안에 줄의 넘버가 존재한다면

                vector<string> words = stringTokenizer(lines[stoi(elements[0]) - 1], ' ');


                if (words.size() < stoi(elements[1])) {
                    console = "해당 줄은 " + to_string(words.size()) + " 단어가 존재합니다.";
                }
                else {
                    string newStr = "";
                    string insertStr = elements[2];
                    int insertPosition = stoi(elements[1]) - 1;

                    if (insertStr.size() > 75) {
                        console = "75바이트 넘는 단어를 삽입할 수 없습니다.";
                    }
                    else {

                        for (int i = 0; i < words.size(); i++) {

                            if (newStr == "") {
                                newStr += words[i];
                            }
                            else {
                                newStr = newStr + " " + words[i];
                            }

                            if (i == insertPosition) {
                                newStr = newStr + " " + insertStr;
                            }
                        }

                        lines[stoi(elements[0]) - 1] = newStr;
                        lines = update(lines);
                        console = "삽입 완료";
                    }

                }
            }
            else {
                console = elements[0] + "라인은 현재 페이지에 없습니다.";
            }
        }
        system("cls");
    }

};

// Delete Instruction ===========================================================================================================
class Delete : public Receiver {
public:
    Delete(vector<string> elements) {
        this->elements = elements;
    }
    void execute() override {
        delete_target();
    }
private:
    vector<string> elements;
    void delete_target() {
        count = count - 20;
        if (!isDisit(elements[0]) || !isDisit(elements[1])) { // 첫번째 인자가 숫자가 아니라면?
            console = "입력이 올바르지 않습니다. 첫번째와 두번째 인자는 양의 정수여야 합니다.";
        }
        else {
            if (count <= stoi(elements[0]) && stoi(elements[0]) <= count + 19) { // 현재 페이지 안에 줄의 넘버가 존재한다면

                vector<string> words = stringTokenizer(lines[stoi(elements[0]) - 1], ' ');


                if (words.size() < stoi(elements[1])) {
                    console = "해당 줄은 " + to_string(words.size()) + " 단어가 존재합니다.";
                }
                else {
                    string newStr = "";
                    int deletePosition = stoi(elements[1]) - 1;

                    for (int i = 0; i < words.size(); i++) {
                        if (i == deletePosition) {
                            continue;
                        }
                        if (newStr == "") {
                            newStr += words[i];
                        }
                        else {
                            newStr = newStr + " " + words[i];
                        }
                    }

                    lines[stoi(elements[0]) - 1] = newStr;
                    lines = update(lines);
                    console = "";
                }

            }
            else {
                console = elements[0] + "라인은 현재 페이지에 없습니다.";
            }
        }
        system("cls");
    }
};

// Search Instruction ===========================================================================================================
class Search : public Receiver {
public:
    Search(vector<string> elements) {
        this->elements = elements;
    }
    void execute() override {
        search();
    }
private:
    vector<string> elements;
    void search() {
        int lineCount = 1;
        int wordCount = 1;

        bool find = false;

        for (int i = 0; i < lines.size(); i++) {
            wordCount = 1;
            vector<string> words = stringTokenizer(lines[i], ' ');
            for (int j = 0; j < words.size(); j++) {

                if (words[j].compare(elements[0]) == 0) {
                    find = true;
                    break;
                }

                wordCount++;
            }
            if (find) {
                break;
            }
            lineCount++;
        }

        if (find) {
            count = lineCount;
            isLastPage = 0;
            isFirstPage = 0;
            console = elements[0] + "는 " + to_string(lineCount) + "번째 줄에서 " + to_string(wordCount) + "번째 단어입니다.";
        }
        else {
            count = count - 20;
            console = elements[0] + "가 전체 문서에 없습니다.";
        }
        system("cls");
    }
};

// Change Instruction ===========================================================================================================
class Change : public Receiver {
public:
    Change(vector<string> elements) {
        this->elements = elements;
    }
    void execute() override {
        change();
    }
private:
    void change() {
        count = count - 20;
        if (elements[1].size() > 75) {
            console = "75바이트가 넘는 단어로는 변경할 수 없습니다.";
        }
        else {
            int changeCount = 0;
            vector<string> words = linesToWords(lines);
            for (int i = 0; i < words.size(); i++) {
                if (words[i].compare(elements[0]) == 0) {
                    words[i] = elements[1];
                    changeCount++;
                }
            }

            if (changeCount > 0) {
                lines = wordsToLines(words);
                console = "변경되었습니다.";
            }
            else {
                console = elements[0] + "가 전체 문서에 없습니다.";
            }
        }
        system("cls");
    }
    vector<string> elements;
};

// Next Instruction =============================================================================================================
class Next : public Receiver {
public:
    void execute() override {
        nextPage();
    }
private:
    void nextPage() {
        if (count + 20 > lines.size()) {
            count = lines.size() - 19;

            console = "";

            if (isLastPage >= 1) {
                console = "마지막 페이지 입니다.";
            }
            isLastPage++;
            
        }
        else {
            console = "";
            isLastPage = 0;
            isFirstPage = 0;
        }

        system("cls");
    }
};

// Prev Instruction =============================================================================================================
class Prev : public Receiver {
public:
    void execute() override {
        prevPage();
    }
private:
    void prevPage() {
        if (count - 40 <= 1) {
            count = 1;
            console = "";

            if (isFirstPage >= 1) {
                console = "첫 페이지 입니다.";
            }
            isFirstPage++;
        }
        else {
            count = count - 40;
            console = "";
            isFirstPage = 0;
            isLastPage = 0;
        }

        system("cls");
    }
};

// Terminate Instruction ========================================================================================================
class Terminate : public Receiver {
public:
    Terminate(string path) {
        this->path = path;
    }
    void execute() override {
        saveAndTerminate();
    }
private:
    void saveAndTerminate() {
        ofstream output(path);
        for (int i = 0; i < lines.size(); i++) {
            if (i == lines.size() - 1) {
                output << lines[i];
            }
            else {
                output << lines[i] + " ";
            }
        }
    }
    string path;
};

class NoCommand : public Receiver {
public:
    void execute() override {
        noCommand();
    }
private:
    void noCommand() {
        count = count - 20;
        console = "올바른 형식의 명령어를 입력하세요.";
        system("cls");
    }
};

template<typename T>
class Command {
public:
    Command(T* receiver) : receiver(receiver) {}
    ~Command() { if (receiver) delete receiver; }

    void execute() {
        receiver->execute();
    }
private:
    T* receiver;
};

int main(int argc, const char* argv[]) {

    string path = "test.txt";
    vector<string> lines = fileToVector(path);

    Command<Print> print_Command(new Print(lines));
    Command<Next> next_Command(new Next());
    Command<Prev> prev_Command(new Prev());
    Command<Terminate> terminate_Command(new Terminate(path));
    Command<NoCommand> no_Command(new NoCommand());

    while (true) {

        print_Command.execute();

        string command = "";
        cin >> command;

        char command_Type = command.at(0);

        if (command.size() == 1) {
            if (command_Type == 'n') {      // Execute next page command
                next_Command.execute();
                continue;
            }

            if (command_Type == 'p') {      // Execute prev page command
                prev_Command.execute();
                continue;
            }

            if (command_Type == 't') {      // Execute terminate command
                terminate_Command.execute();
                break;
            }
        }

        if (command.size() > 3 && validationCheck(command)) {

            vector<string> elements = parseCommand(command);

            if (command_Type == 'i' && elements.size() == 3) {          // Execute Insert command
                Command<Insert> insert_Command(new Insert(elements));
                insert_Command.execute();
                continue;
            }

            if (command_Type == 'd' && elements.size() == 2) {          // Execute Delete command
                Command<Delete> delete_Command(new Delete(elements));
                delete_Command.execute();
                continue;
            }

            if (command_Type == 'c' && elements.size() == 2) {          // Execute Change command
                Command<Change> change_Command(new Change(elements));
                change_Command.execute();
                continue;
            }

            if (command_Type == 's' && elements.size() == 1) {          // Execute Search command
                Command<Search> search_Command(new Search(elements));
                search_Command.execute();
                continue;
            }

        }
        no_Command.execute();           // error
    }
    getchar();
}