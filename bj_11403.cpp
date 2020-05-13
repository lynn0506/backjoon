#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <queue> 
#include <string> 

using namespace std;
int Map[101][101] = {};
int N;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            cin >> Map[i][j];
        }
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            if(Map[i][j] == 1) {
                for(int k = 0; k<N; k++) {
                    if(Map[j][k] == 1) {
                        Map[i][k] = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            if(Map[i][j] == 1) {
                for(int k = 0; k<N; k++) {
                    if(Map[j][k] == 1) {
                        Map[i][k] = 1;
                    }
                }
            }
        }
    }
       

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            if(Map[i][j] == 2)
                cout << 1 << " ";
            else 
                cout << Map[i][j] << " ";
        }
        cout << "\n";
    }

}