#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int w, h;
int cnt = 0;
int visit[51][51] = {};
int home[51][51] = {};
int pos[8][2]  = {
    {0, 1}, {0, -1}, {-1, -1},
    {1, 0}, {1, -1}, {-1, 0},
    {-1, 1}, {1, 1}
};

void DFS(int x, int y, int home[51][51]){
    if(x < 0 || y < 0 || x >= h || y >= w){
        return;
    }
    visit[x][y] = 1;
    for(int i = 0; i<8; i++) {
        int X = x + pos[i][0];
        int Y = y + pos[i][1];
        if(X>=0 && Y>=0 && X<h && Y<w) {
            if(visit[X][Y] != 1 && home[X][Y] == 1) {
                DFS(X, Y, home);
            } 
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> w >> h;
    while(w != 0 && h != 0) {
        for(int i = 0; i<51; i++) {
            memset(visit[i], 0, sizeof(visit[i]));
        }
        cnt = 0;
        for(int i =0; i<h; i++) {
            for(int j = 0; j<w; j++) {
                cin >> home[i][j];
            }
        }

        for(int i = 0; i<h; i++) {
            for(int j = 0; j<w; j++) {
                if(visit[i][j] != 1 && home[i][j] == 1) {
                    DFS(i, j, home);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        cin >> w >> h;
    }
}