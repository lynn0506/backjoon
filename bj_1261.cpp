#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int mov[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0}
};
int home[101][101] = {};
int visit[101][101] = {};
int dijkstra[101][101] = {};

int main() {
    int N, M;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    cin.ignore();

    for(int i = 0; i<N; i++) {
        string str;
        cin >> str;
        for(int j= 0; j<M; j++) {
            home[i][j] = stoi(str.substr(j, 1));
        }
    }

    queue<pair<int, int> > pq;
    pq.push(pair<int, int>(0, 0) );

    for(int i = 0; i<100; i++) {
        memset(visit[i], 100, sizeof(visit[i]));
    }
    visit[0][0] = 0;
    while(!pq.empty()) {
        int Nx = pq.front().first;
        int Ny = pq.front().second;
        pq.pop();

        for(int i = 0; i<4; i++) {
            int X = Nx + mov[i][0];
            int Y = Ny + mov[i][1];

            if(X >= 0 && Y >= 0 && X < N && Y < M) {
                if(visit[X][Y] > visit[Nx][Ny] + home[X][Y]) {
                    visit[X][Y] = visit[Nx][Ny] + home[X][Y];
                    pq.push(pair<int, int>(X, Y));  
                }       
            }
        }
    }   

    cout << visit[N-1][M-1] << endl;
}
