#include <iostream> 
#include <string> 
#include <algorithm> 
#include <map> 
#include <queue> 

using namespace std; 

int main() {
    int bingo[6][6] = {};
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    map<int, pair<int, int> > M;
    queue<int> Q;

    for(int i = 0; i<5; i++) {
        for(int j = 0; j<5; j++) {
            int tar;
            cin >> tar;

            bingo[i][j] = tar;
            M[tar] = make_pair(i, j);
        }
    }

    for(int i = 0; i<25; i++) {
        int ret;
        cin >> ret;
        Q.push(ret);
    }

    int cnt = 1;
    int num = 0;
    int tri_one = 0;
    int tri_two = 0;

    while(!Q.empty()) {
        int turn = Q.front();
        Q.pop();

        pair<int, int> X = M[turn];
        bingo[5][X.second]++;
        bingo[X.first][5]++;

        if(X.second == X.first) {
            tri_one++;
            if(tri_one == 5) {
                num++;
            } 
        } 
        if(X.second + X.first == 4) {
            tri_two++;
            if(tri_two == 5) {
                num++;
            }
        }

        if(bingo[5][X.second] == 5) {
            num++;
        } 
        if(bingo[X.first][5] == 5) {
            num++;
        }
        
        
        if(num >= 3) {
            cout << cnt << "\n";
            return 0;
        }
        cnt++;
    }
}
