#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    int prime[10001] = {};
    prime[1] = 1;

    for(int i = 2; i<= 10000; i++) {
        if(prime[i] != 1) {
            for(int j = i*2; j<= 10000; j += i) {
                prime[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool check = false;
        int a = 0;
        int b = 0;
        int min = 10000;

        for(int i = 2; i<= num/2; i++) {
            if(prime[i] == 0 && prime[num-i] == 0) {
                if(num-2*i < min) {
                    a = i;
                    b = num-i;
                }
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}