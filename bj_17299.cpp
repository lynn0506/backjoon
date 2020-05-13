#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

int ans[1000001] = {};
int org[1000001] = {};
int org_cnt[1000001] = {};
int cnt[1000001] = {};
int N;
stack<pair<int, int> > ST;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);    
    ios_base::sync_with_stdio(false);
    cin >> N;

    stack<pair<int, int> > q;
    memset(ans, -1, sizeof(ans));

    for(int i = 0; i < N; i++) {
        int tar;
        cin >> tar;
        org[i] = tar;
        cnt[tar]++;
    }

    for(int i = 0; i<N; i++) {
        org_cnt[i] = cnt[org[i]];
    }

    for(int i = 0; i<N; i++) {
        int target = org_cnt[i];

        while(!ST.empty()) {
            if(target > ST.top().first) {
                ans[ST.top().second] = org[i];
                ST.pop();
            } else {
                break;
            }
        }
        ST.push(pair<int, int>(target, i));
    }

    for(int i = 0; i<N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}