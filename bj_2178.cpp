#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int N, M, x, y, nx, ny;
int Min = 100000000;
int visit[101][101] = {};
int maze[101][101] = {};

int Move[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0},
};

void BFS(){
    queue <pair<int, int> > q;
    q.push(pair<int, int>(0, 0));
    visit[0][0] = 1;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(x == N-1 && y == M-1)
            return;
        
        for(int i = 0; i<4; i++) {
            nx = x + Move[i][0];
            ny = y + Move[i][1];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if(visit[nx][ny] == 0 && maze[nx][ny] == 1) {
                    q.push(pair<int, int>(nx, ny));
                    visit[nx][ny] = visit[x][y] + 1;
                }
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for(int j = 0; j<M; j++) {
            maze[i][j] = stoi(str.substr(j,1));
        }
    }
    BFS();
    cout << visit[N-1][M-1] << "\n";
    return 0;    
}