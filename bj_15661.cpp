#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    int arr[21][21] = {};
    int sum = 40000;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int k = 1; k < N; k++)  {
        vector<int> permu;

        for(int i = 0; i<k; i++) {
            permu.push_back(0);
        }
        for(int i = 0; i<N-k; i++) {
            permu.push_back(1);
        }

        do {
            vector<int> arr2;
            vector<int> arr3;
            int SO = 0;
            int BO = 0;

            for(int i = 0; i<N; i++) {
               if(permu[i] == 0)  {
                    arr2.push_back(i);
                } else {
                    arr3.push_back(i);
                }
            }

            for(int i = 0; i< arr2.size(); i++) {
                for(int j = 0; j<i; j++) {
                    SO += arr[arr2[i]][arr2[j]] + arr[arr2[j]][arr2[i]];
                }
            }

            for(int i = 0; i<arr3.size(); i++) {
                for(int j = 0; j<i; j++) {
                    BO += arr[arr3[i]][arr3[j]] + arr[arr3[j]][arr3[i]];
                }
            }

            int differ = (SO > BO) ? (SO - BO) : (BO - SO);
            if(differ < sum) {
                sum = differ;
            }
        } while(next_permutation(permu.begin(), permu.end()));
    }
    cout << sum << endl;
} 
