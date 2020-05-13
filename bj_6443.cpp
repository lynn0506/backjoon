#include <iostream> 
#include <algorithm> 
#include <string> 
#include <cmath> 
#include <climits> 
#include <vector> 
#include <stack> 
#include <set> 

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i = 0; i<N; i++) {
        string A;
        cin >> A;
        vector<char> V;

        for(int j = 0; j<A.size(); j++) {
            V.push_back(A[j]);
        }
        sort(V.begin(), V.end());
        do {
            for(int j = 0; j<V.size(); j++) 
            {
                cout << V[j];
            } 
            cout << "\n";

        } while(next_permutation(V.begin(), V.end()));

    }
    return 0;

}