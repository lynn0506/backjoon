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
bool visit[100002] = {};
int cnt[100002] = {};

void BFS() {
    visit[N] = true;
    cnt[N] = 1;
    queue<int> Q;
    Q.push(N);

    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();

        int arr[3] = {x-1, x+1, 2*x};
        for(int i = 0; i<3; i++) {
            if(arr[i]>=0 && arr[i] <= 100000) {
                if(visit[arr[i]] == false) {
                    visit[arr[i]] = true;
                    dp[arr[i]] = dp[x] + 1;
                    Q.push(arr[i]);
                    cnt[arr[i]] = cnt[x];
                }
                else if(dp[arr[i]] == dp[x] + 1) {
                    cnt[arr[i]] += cnt[x];
                }
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
    cout << dp[K] << "\n" << cnt[K];
    
}
