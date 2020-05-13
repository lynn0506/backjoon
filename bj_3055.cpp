#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <queue> 
#include <string.h> 
#include <cstdlib>
#include <vector> 
#include <math.h>

using namespace std;

int N, M;
bool visit[52][52] = {};
int Move[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0}
};
pair<int, int> water[52*52];
int wat_cnt = 0;
char Map[52][52] = {};
int cnt = 0; 

void BFS(int x, int y) {
    queue<pair<int, int> > waters;
    queue<pair<int, int> > goesum;

    for(int i = 0; i<wat_cnt; i++) {
        waters.push(water[i]);
    }
    goesum.push(make_pair(x, y));
    visit[x][y] = true;

    while(!goesum.empty()) {
        int siz = waters.size();
        for(int i = 0; i<siz; i++) {
            pair<int, int> temp = waters.front();
            waters.pop();
            for(int j = 0; j<4; j++) {
                int X = temp.first + Move[j][0];
                int Y = temp.second + Move[j][1];

                if(X >= 0 && X < N && Y >= 0 && Y < M && visit[X][Y] == false) {
                    if(Map[X][Y] == '.' || Map[X][Y] == 'S') {
                        Map[X][Y] = '*';
                        waters.push(make_pair(X, Y));
                    }
                }
            }
        }
        siz = goesum.size();
        for(int i = 0; i<siz; i++) {
            pair<int, int> Go = goesum.front();
            goesum.pop();
            for(int j = 0; j<4; j++) {
                int X = Go.first + Move[j][0];
                int Y = Go.second + Move[j][1];

                if(X >= 0 && X < N && Y >= 0 && Y < M && visit[X][Y] == false ) {
                    if(Map[X][Y] == 'D') {
                        cout << (cnt+1) << "\n";
                        return;
                    }
                    if(Map[X][Y] == '.') {
                        Map[X][Y] = 'S';
                        visit[X][Y] = true;
                        goesum.push(make_pair(X, Y));
                    }
                }
            }
        }
        cnt++;
    }
    cout << "KAKTUS" << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M ;

    int x, y = 0;
    memset(visit, false, sizeof(visit));
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            cin >> Map[i][j];
            if(Map[i][j] == '*') {
                water[wat_cnt++] = pair<int, int>(i, j);
            } else if(Map[i][j] == 'S') {
                x = i;
                y = j;
            } 
        }
    }
    BFS(x, y);
}