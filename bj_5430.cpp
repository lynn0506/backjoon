#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        string p;
        cin >> p;
        
        int n;
        cin >> n;
        
        char temp;
        int num;
        deque<int> dq;
        bool rev = false, error = false;

        cin >> temp;
        for(int i = 0; i<n; i++) {
            if(i == 0) cin >> num;
            else cin >> temp >> num;
            dq.push_back(num);
        }
        cin >> temp;
        
        for(int i = 0; i<p.length(); i++) {
            if(p[i] == 'R') {
                rev = !rev;
            } else {
                if(dq.empty()) {
                    error = true;
                    break;
                } else {
                    if(rev) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                    n--;
                }
            }
        }
        if(error) {
            cout << "error" << '\n';
            continue;
        }
        
        cout << '[';

        for(int i = 0; i<n; i++) {
            if(i != 0) cout << ',';
            if(rev) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
        }
        cout <<']' << '\n';
    }
}

