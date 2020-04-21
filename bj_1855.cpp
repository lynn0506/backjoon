#include <iostream> 
#include <string> 
#include <math.h> 
#include <algorithm> 
#include <utility> 

using namespace std;
  

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;
    cin.ignore();

    string M;
    cin >> M; 

    int y = M.size() / n;
    if(M.size() % n != 0) {
        y += 1;
    }
    int idx = 0;

    char arr[200][20] = {};
    for(int i = 0; i< y; i++) {
        for(int j = 0; j<n; j++) {
            if(idx != M.size()) {
                if(i % 2 == 0)
                    arr[i][j] = M.at(idx++);
                else
                    arr[i][(n-1-j)] = M.at(idx++);
            }
        }
    }


    for(int j = 0; j<n; j++) {
        for(int i = 0; i<y; i++) {
            if(arr[i][j] != 0) {
                cout << arr[i][j];
            }
        }
    }
    cout << "\n";
    return 0;
}
