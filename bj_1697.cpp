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

void BFS() {
    queue<int> Q; 
    visit[N] = true;
    Q.push(N);
    
    while(!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int arr[3] = {x+1, x-1, 2*x};

      for(int i = 0; i<3; i++) {
        if(visit[arr[i]] == false && arr[i]>= 0 && arr[i] <= 100000) {
            dp[arr[i]] = dp[x] + 1;
            visit[arr[i]] = true;
            Q.push(arr[i]);
        }
      }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(fals);
    cin >> N >> K;  

    memset(visit, false, sizeof(visit));
    BFS();
    cout << dp[K];

}e
