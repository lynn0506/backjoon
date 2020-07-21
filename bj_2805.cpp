#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std;

#define ll long long
vector<int> v;

long slice(int mid) {
    long sum = 0;
    for(int i = 0; i<v.size(); i++) {
        sum += (v[i]-mid > 0) ? v[i]-mid : 0;
    }
    return sum;
}

void binarySearch(int str, int end, ll r_sum) {
    int mid = 0;
    while(str <= end) {
        mid = (str + end) / 2;
        if(slice(mid) >= r_sum) {
            str = mid + 1;
        } else {
            end = mid - 1;
        }   
    }
    cout << end;
}

int main() {
    ll N, M;
    cin >> N >> M;

    ll n;

    for(int i = 0; i<N; i++) {
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    binarySearch(0, 2000000000, M);
}

