#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int Max = 0;
int N;
int P[10001] = { };
int arr[10001] = { };

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i = 1; i<=N; i++) {
        cin >> P[i];
        arr[i] = P[i];
    }
    arr[1] = P[1];

    for(int i = 2; i<=N; i++) {
        for(int j = 1; j<= i; j++) {
            arr[i] = min(arr[i], arr[i-j] + P[j]);
        }
    }

    cout << arr[N] << "\n";
}