#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <queue> 
#include <string> 

using namespace std;

int main() {
    int N;
    int arr[501][501] = {};

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<=i; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int DP[501][501] = {};
    DP[0][0] = arr[0][0];

    for(int i = 1; i < N; i++) {
        for(int j = 0; j<= i; j++) {
            DP[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i<N; i++ ) {
        for(int j = 0; j<= i; j++) {
            if(DP[i][j] < DP[i-1][j] + arr[i][j]) {
                DP[i][j] = DP[i-1][j] + arr[i][j];
            }
            if(j-1 >= 0) {
                if(DP[i][j] < DP[i-1][j-1] + arr[i][j]) {
                    DP[i][j] = DP[i-1][j-1] + arr[i][j]; 
                }
            }
        }
    }

    int Max = 0;
    for(int i = 0; i<N; i++)
    {
        if(DP[N-1][i] > Max)
            Max = DP[N-1][i];
    }

    cout << Max << "\n";
    return 0;
}