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


int N, K;
int dp[100002] = {};
int route[100002] = {};
bool visit[100002] = {};


void print() {
    stack<int> S;
    S.push(K);

    int curr = route[K];

    while(route[curr] != curr) {
        S.push(curr);
        curr = route[curr];
    }

    S.push(curr);

    while(!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}

void BFS() {
    visit[N] = true;
    route[N] = N;

    queue<int> Q;
    Q.push(N);

    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();

        if(x == K) {
            break;
        }
        int arr[3] = {x-1, x+1, 2*x};
        for(int i = 0; i<3; i++) {
            if(visit[arr[i]] == false && arr[i]>=0 && arr[i] <= 100000) {
                visit[arr[i]] = true;
                dp[arr[i]] = dp[x] + 1;
                route[arr[i]] = x;
                Q.push(arr[i]);
            }
        }
    }

}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;  

    memset(visit, false, sizeof(visit));
    BFS();
    cout << dp[K] << "\n";
    if(dp[K] >= 1)
        print();
    else {
        cout << K;
    }
}
