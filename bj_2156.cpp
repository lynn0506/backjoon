#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int grape[10001] = {};
    for(int i = 1; i<=n; i++) {
        cin >> grape[i];
    }

    int dp[10001] = {};
    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];

    for(int i = 3; i<=n; i++) {
        int one = dp[i-3] + grape[i-1] + grape[i];
        int two = dp[i-2] + grape[i];
        int three = dp[i-1];
        dp[i] = max(max(one, two), three);
    }
    cout << dp[n] << "\n";
}