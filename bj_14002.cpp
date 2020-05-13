#include <iostream>
#include <algorithm>
#include <string>
#include <stack> 

using namespace std;

int main() {
    int N;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    long long permu[1000001] = {};

    for(int i = 0; i<N; i++) {
        cin >> permu[i];
    }
    long long dp[1000001] = {};

    long long max = 0;
    for(int i = 0; i<N; i++) {
        dp[i] = 1;
        for(int j = 0; j<i; j++) {
            if(permu[i] > permu[j] && dp[j]+1 > dp[i] ) {
                dp[i] = dp[j] + 1;
                if(max < dp[i]) 
                    max = dp[i];
            }
        }
    }
    stack<int> S;
    for(int i = N-1; i>= 0; i--) {
        if(max == dp[i]) {
            S.push(permu[i]);
            max--;
        }
        if(max == 0) {
            break;
        }
    }
    if(S.size() == 0) {
        cout << 1 << "\n";
        cout << permu[0] << "\n";
        return 0;
    }
    else
        cout << S.size() << "\n";

    long long siz = S.size();
    for(long long i = 0; i<siz; i++) {
        cout << S.top() << ' ';
        S.pop();
    }

    


}