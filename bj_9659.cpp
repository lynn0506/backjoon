#include <iostream>
#include <string> 

using namespace std;

int main() {
    long long n;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    int winner = 0;
    
    if(n <= 3) {
        cout << "SK";
        return 0;
    }

    if(n%2 == 1) {
        cout << "SK";
        return 0;
    } else {
        cout << "CY";
        return 0;
    }

    // 8 -> 상근 1개 -> 창영 3개 -> 상근1개 : 창영 win
    // 7 -> 상근 3개 -> 창영 1개/3개 : 상근 win
    // 6 -> 상근 1개 -> 창영 1개 -> 상영 : 창영 win
    // 5 -> 상근 1개 -> 창영 1개 -> : 상근 win
    // 4 -> 상근 : 창영 win
}