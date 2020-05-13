#include <iostream>
#include <algorithm>
#include <string>
// 꽤나 어려웠음 ㅠ 다시 풀기
using namespace std;
int L, C;
string moeum[5] = {"a", "e", "i", "o", "u"};
int cnt = 0;
int cnt2 = 0;

void check (int ind[16], string alphabet[16]) {
    cnt = 0;
    cnt2 = 0;
    for(int i = 0; i<C; i++) {
        if(ind[i] == 0) {
            for(int j = 0; j<5; j++) {
                if(moeum[j].compare(alphabet[i]) == 0) {
                    cnt++;
                }
                }
            }
        }
    cnt2 = L - cnt;
    if(cnt > 0 && cnt2 >=2) {
        for(int i = 0; i<C; i++) {
            if(ind[i] == 0)
                cout << alphabet[i];
        }
        cout << "\n";
    } 
}


int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;
    string alphabet[16] = {};

    for(int i = 0; i<C; i++) {
        cin >> alphabet[i];
    }

    sort(alphabet, alphabet+C);
    int ind[16] = {};

    for(int i = 0; i<L; i++) {
        ind[i] = 0;
    }
    for(int i = L; i<C; i++) {
        ind[i] = 1;
    }

    do {
        check(ind, alphabet);
    } while(next_permutation(ind, ind+C));
}

