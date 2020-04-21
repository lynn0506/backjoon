#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <queue> 
#include <string> 
#include <cstdlib>
#include <vector> 
#include <math.h>
#include <climits> 

using namespace std;
int L, N, K;
pair<int, int> Apple[101];
int Map[102][102] = {};
map<int, char> order;
queue<pair<int, int> > Q;

int X_head, Y_head;
int X_tail, Y_tail;
int length = 1;
int Move[8][2] = {
    {0, 1}, {1, 0}, {1, 1},
    {1, -1}, {-1, 1}, {-1, 0},
    {0, -1}, {-1, -1}
};

void search(int dir, int sec) 
{
    
    if(dir == 0) {
        Y_head++;
    } else if(dir == 1) {
        X_head++;
    } else if (dir == 2) {
        Y_head--;
    } else {
        X_head--;
    }

    if(X_head >= N || Y_head >= N || X_head < 0 || Y_head < 0) {
        cout << (sec+1) << "\n";
        return;
    } else if(Map[X_head][Y_head] == 2) {
        cout << (sec+1) << "\n";
        return;
    }

    bool check = false;
    if(Map[X_head][Y_head] == 1) {
        check = true;
    }
    Q.push(make_pair(X_head, Y_head));
    if(!check) {
        Map[X_tail][Y_tail] = 0;
        Q.pop();
        pair<int, int> temp = Q.front();
        X_tail = temp.first;
        Y_tail = temp.second;
    }

    Map[X_head][Y_head] = 2;
    sec++;

    // for(int i = 0; i<N; i++) {
    //     for(int j = 0; j<N; j++) {
    //         cout << Map[i][j] << " ";
    //     } cout << "\n";
    // } cout << "\n" << sec << "\n";

    if(order.find(sec) != order.end()) {
        char D = order[sec];
        if(D == 'D') {
            switch(dir) {
                case(0):
                    dir = 1;
                    break;
                case(1):
                    dir = 2;
                    break;
                case(2):
                    dir = 3;
                    break;
                case(3):
                    dir = 0;
                    break;
            }
        } else {
            switch(dir) {
                case(0):
                    dir = 3;
                    break;
                case(1):
                    dir = 0;
                    break;
                case(2):
                    dir = 1;
                    break;
                case(3):
                    dir = 2;
                    break;
            }
        }
    }
    search(dir, sec);
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;

    for(int i = 0; i<K; i++) {
        int x, y;
        cin >> y >> x;
        Map[y-1][x-1] = 1;
        Apple[i] = make_pair(x-1, y-1);
    }
    cin >> L;
    for(int i = 0; i<L; i++) {
        int X;
        char C;
        cin >> X;
        cin.ignore();
        cin >> C;
        order[X] = C;
    }

    X_head = 0;
    Y_head = 0;
    Y_tail = 0;
    X_tail = 0;

    Q.push(make_pair(0, 0));
    Map[X_head][Y_head] = 2;
    search(0, 0);
    return 0;
}
