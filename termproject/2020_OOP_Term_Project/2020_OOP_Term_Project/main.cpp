#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]) {

    ifstream myfile ("test.txt");

    
    if (!myfile.is_open()) {
        cout << "Can't find the file" << endl;
    }


    char alpha;                 // [알파벳]
    string word = "";           // [단어]
    string line = "";           // [라인]

    vector<string> lines;        // [페이지]

    while (myfile) {

        alpha = myfile.get();
        
        word += alpha;

        if (alpha == ' ' || myfile.eof())
        {
            if ((line + word).length() - 1 == 75) {
                line += word;

                lines.push_back(line);

                word = "";
                line = "";

            }
            else if ((line + word).length() - 1 > 75){

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

    string inputStr;
    int count = 1;

    for (auto s1 : lines) {

        if (count > 20) {
            break;
        }

        if (count < 10) {
            cout << " " << count << "| " << s1 << endl;
        }
        else {
            cout << count << "| " << s1 << endl;
        }
        count++;
    }

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "temp" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> inputStr;
    cout << "------------------------------------------------------------------------------------------------" << endl;
   
    return 0;
}
