#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <vector> 
#include <string.h> 

using namespace std;

int Move[4][2] = {
    {0, -1}, {0, 1},
    {1, 0}, {-1, 0}
};

int M, N, K;
int bat[51][51] = {};

void BFS(int x, int y) {
    bat[x][y] = 2;
    bool check = false;
    vector<pair<int, int> > V;

    for(int i = 0; i<4; i++) {
        int X = x + Move[i][0];
        int Y = y + Move[i][1];

        if(X >= 0 && X < N && Y >= 0 && Y < M) {
            if(bat[X][Y] == 1) {
                BFS(X, Y);
            }
        }
    }

    if(check == false)
        return;

}

int main() {
    int T;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> T;

    for(int k = 0; k<T; k++) {
        for(int i = 0; i<N; i++)
            memset(bat[i], 0, sizeof(bat[i]));

        cin >> M >> N >> K;
        int X, Y;
        for(int i = 0; i<K; i++) {
            cin >> X >> Y;
            bat[Y][X] = 1;
        }

        int sum = 0;
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++) {
                if(bat[i][j] == 1) {
                    BFS(i, j);
                    sum += 1;
                }
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}