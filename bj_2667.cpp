#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int home[30][30] = {};
int visit[30][30] = {};

int N;
int cnt;
int Move[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check (int x, int y) {
    if(x>= 0 && x<=N-1 && y>= 0 && y<= N-1) {
        return true;
    }
    return false;
}

void DFS(int x, int y) {
    visit[x][y] = 1;
    if(home[x][y] == 1) {
        cnt++;

        for(int i = 0; i<4; i++) {
            if(check((x + Move[i][0]), (y + Move[i][1])))  {
                if(visit[x+Move[i][0]][y+Move[i][1]] != 1) {
                    DFS(x + Move[i][0], y + Move[i][1]);
                }
            }   
        }
    }
    return;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string number;
        cin >> number;
        for(int j = 0; j<N; j++) {
            home[i][j] = stoi(number.substr(j, 1));
            visit[i][j] = 0;
        }
    }

    int arr[700] = {};
    int count = 0;

    for(int i = 0; i< N; i++) {
        for(int j = 0; j<N; j++) {
            if(visit[i][j] != 1 && home[i][j] == 1) {
                cnt = 0;
                DFS(i, j);
                arr[count] = cnt;
                count++;
            }
        }
    }
    sort(arr, arr+count);

    cout << count << "\n";
    for(int i = 0; i<count; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}