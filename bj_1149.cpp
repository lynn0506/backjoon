#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int sum = 2000000000;
    int color[1001][3] = {};
    int dp[1001][3] = {};

    for(int i = 0; i<N; i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for(int i = 1; i<N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2];
    }

    cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2])<< "\n";
    return 0;
}