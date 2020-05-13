#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int Move[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0}
};
int N, M;
int tomato[1001][1001] = { };
int visit[1001][1001] = { };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    int fruit = 0;
    queue<pair<int, int> > q;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) 
            {
                q.push(pair<int, int>(i, j));
            }
        }
    }
    if(q.size() == 0) {
        cout << -1 << "\n";
        return 0;
    }

    queue<queue<pair<int, int> > > set;
    set.push(q);
    int cnt = 0;
    while(!set.empty()) {
        queue<pair<int, int> > del = set.front();
        set.pop();
        queue<pair<int, int> > qq;
        while(!del.empty()) {
            int x = del.front().first;
            int y = del.front().second;
            del.pop();
            for(int i = 0; i<4; i++) {
                int NX = x + Move[i][0];
                int NY = y + Move[i][1];

                if(NX >= 0 && NY >= 0 && NX < N && NY < M) {
                    if(visit[NX][NY] != 1 && tomato[NX][NY] == 0) {
                        tomato[NX][NY] = 1;
                        visit[NX][NY] = 1;
                        qq.push(pair<int, int>(NX, NY));
                    }
                }
            }
        }
        if(!qq.empty()) {
            set.push(qq);
        }
        cnt++;
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            if(tomato[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << (cnt-1) << endl;
}