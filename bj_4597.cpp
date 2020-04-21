#include <iostream>
#include <algorithm> 
#include <string> 


using namespace std;

int main() {
    string Str;
    getline(cin, Str);

    while(Str.compare("#") != 0) {
        int cnt = 0;
        for(int i = 0; i<Str.size(); i++) {
            if(Str.at(i) == '1') {
                cnt++;
            }
        }
        if(Str.at(Str.size()-1) == 'e') {
            if(cnt%2 == 1) {
                cout << Str.substr(0, Str.size() -1) << "1\n";
            } else {
                cout << Str.substr(0, Str.size() -1) << "0\n";
            }
        }  else {
            if(cnt %2 == 1) {
                cout << Str.substr(0, Str.size() -1) << "0\n";
            } else {
                cout << Str.substr(0, Str.size() -1) << "1\n";
            }
        }

        getline(cin, Str);
    }
}
