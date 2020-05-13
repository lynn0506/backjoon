#include <iostream> 
#include <algorithm> 
#include <string> 
#include <cmath> 
#include <climits> 
#include <vector> 
#include <stack> 
#include <set> 

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<char> V;
    for(int i = 0; i<S.size(); i++) {
        V.push_back(S[i]);
    }   
    sort(V.begin(), V.end());
    int cnt = 0;
    do {
        char pos = V[0];
        bool check = false;
        for(int i = 1; i<S.size(); i++) {
            if(V[i] == pos){
                check = true;
                break;
            }
            pos = V[i];
        }

        if(check == false) {
            cnt++;
        }
    } while(next_permutation(V.begin(), V.end()));

    cout << cnt << "\n";
}