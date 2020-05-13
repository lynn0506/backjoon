#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string print = "Goldbach's conjecture is wrong.\n";
    int prime[1000002] = {};

    for(int i = 2; i<=1000000; i++) {
        if(prime[i] != 1) {
            for(int j = 2*i; j<=1000000; j+= i) {
                prime[j] = 1;
            }
        }
    }
    prime[1] = 1;
    prime[2] = 1;

    while(N != 0) {
        bool check = false;
        for(int i = 3; i<= N; i += 2) {
            if(prime[i] == 0 && prime[N-i] == 0) {
                cout << N << " = " << i << " + " << (N-i) << "\n"; 
                check = true;
                break;
            }
        }
        if(check == false) {
            cout << print;
        }
        cin >> N;
    }
}