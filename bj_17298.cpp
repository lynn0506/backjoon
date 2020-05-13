#include <iostream>
#include <stack>

using namespace std;
int arr[1000001] = {};
int ans[1000001] = {};
stack<pair<int, int> > St;

int main() {
    int N;
    cin >> N;
    memset(ans, -1, sizeof(ans));

    for(int i = 0; i<N; i++) {
        cin >> arr[i];
        
        while(!St.empty()) {
            if(arr[i] > St.top().first) {
                ans[St.top().second] = arr[i];
                St.pop();
            } else {
                break;
            }
        }
        St.push(pair<int, int>(arr[i], i));
    }

    for(int i = 0; i<N; i++) {
        cout << ans[i] << " ";
    }
}