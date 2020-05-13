#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[101] = {};

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    string ap[4] = {"+", "-", "*", "/"};
    int combi[11] = { };
    int idx = 0;
    for(int i = 0; i<4; i++) {
        int ret;
        cin >> ret;
        for(int j = 0; j < ret; j++) {
            combi[idx++] = i;
        }
    }


    int pre = arr[0];
    for(int i = 1; i<N; i++) {
        int post = arr[i];
        if(combi[i-1] == 0) {
            pre += post;
        } else if(combi[i-1] == 1) {
            pre -= post;
        } else if(combi[i-1] == 2) {
            pre *= post;
        } else if(combi[i-1] == 3) {
            pre /= post;
        }
    }
    int max = pre;
    int min = pre;
    while(next_permutation(combi, combi+(N-1))){
        int pre = arr[0];

        for(int i = 1; i<N; i++) {
            int post = arr[i];
            if(combi[i-1] == 0) {
                pre += post;
            } else if(combi[i-1] == 1) {
                pre -= post;
            } else if(combi[i-1] == 2) {
                pre *= post;
            } else if(combi[i-1] == 3) {
                if(pre < 0) {
                    if(post < 0) {
                        pre = abs(pre) / abs(post);
                    } else {
                        pre = abs(pre) / post;
                        pre *= (-1);
                    }
                } else {
                    if(post <0) {
                        pre /= abs(post);
                        pre *= (-1);
                    } else {
                        pre /= post;
                    }
                }
            }
        }
        if(pre > max) {
            max = pre;
        }
        if(pre < min) {
            min = pre;
        } 

        cout << "\n";   
    }
    cout << max << "\n";
    cout << min << "\n";
    // 0 : "+" , 1: "-" , 2: "X", 3:"/"

}