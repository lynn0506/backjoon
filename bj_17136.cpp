#include <iostream> 
#include <string> 
#include <math.h> 
#include <algorithm> 
#include <utility> 
#include <set> 
#include <queue> 

using namespace std;

int color[10][10] = {};
int nums[6] = {};
int blocks = 0;
int check = false;
int MIN;

bool valid(int x, int y, int siz) {
    for(int i = x; i< x+ siz; i++) {
        for(int j = y; j<y+siz; j++) {
            if(i >= 0 && i<10 && j>= 0 && j<10) {
                if(color[i][j] != 1)
                    return false;
            } else {
                return false;
            }
        }
    }
    return true;
}

void change(int x, int y, int siz, int col) {
    for(int i = x; i<x+siz; i++) {
        for(int j = y; j<y+siz; j++) {
            color[i][j] = col;
        }
    }
}

void DFS(int siz, int ans) {
    if(siz == blocks) {
        if(ans < MIN)
            MIN = ans; 

        check = true; 
        return;
    }

    for(int x = 0; x < 10; x++) {
        for(int y = 0; y<10; y++) {
            if(color[x][y] == 1) {
                for(int k = 5; k> 0; k--) {
                    if(nums[k] < 5 && valid(x, y, k)) {
                        change(x, y, k, 2);
                        nums[k]++;
                        DFS(siz+(k*k), ans+1);
                        nums[k]--;
                        change(x, y, k, 1);
                    }
                }
                return;
            }
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue<pair<int, int> > S;
    
    blocks = 0; 
    
    for(int i = 0; i<10; i++) {
        for(int j = 0; j<10; j++) {
            cin >> color[i][j];
            if(color[i][j]) {
                S.push(make_pair(i, j));
                blocks++;
            }
        }
    }
    if(blocks == 0) {
        cout << 0 << "\n"; 
        return 0;
    } else {
        MIN = blocks;
        DFS(0, 0);
    }

    if(check == true)
        cout << MIN<< "\n";
    else
        cout << -1 << "\n";
}

