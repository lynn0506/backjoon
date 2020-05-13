#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int mod = 10007;

int main() {
    int N;
    cin >> N;

    int num[1001][10] = {};

    for(int i = 0; i <= 9; i++) {
        num[1][i] = 1;
    }

    for(int i = 2; i<= 1000; i++) {
        for(int j = 0; j<= 9; j++) {
            for(int k = 0; k<= j; k++) {
                num[i][j] += num[i-1][k];
                num[i][j] = num[i][j] % mod;
            }
        }
    }

    int cnt = 0;
    for(int i = 0 ; i<= 9; i++) {
        cnt += num[N][i];
        cnt %= mod;
    }

    cout << cnt << endl;

}