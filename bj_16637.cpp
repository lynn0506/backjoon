#include <iostream> 
#include <string> 
#include <math.h> 
#include <algorithm> 
#include <utility> 
#include <set> 
#include <queue> 
#include <limits.h>

using namespace std;
int N;
string M;

long long MAX = INT_MIN;
int check[20] = {};
char* CH[20][2] = {};

void change(int str, long int sum, bool ch) {

    if(!ch) {
        CH[str-1][1] = CH[str-1][0];
        CH[str+1][1] = CH[str+1][0];
    } else {
        string S = to_string(sum);
        char * SS = new char[21];
        for(int i = 0; i<S.size(); i++) {
            SS[i] = S.at(i);
        }
        CH[str-1][1] = SS;
        CH[str+1][1] = SS;
    }
}

bool checking(int str) {
    if(str-2 >= 0 && str+2 < N) {
        if(check[str-2] == 0 && check[str+2] == 0)
            return true;
    }
    else if(str-2 < 0 && str+2 > N) {
        return true;
    } else if(str-2 < 0) {
        if(check[str+2] == 0)
            return true;
    } else {
        if(check[str-2] == 0)
            return true;
    }
    return false;
}

void calculate() {
    long int sum = atol(CH[0][1]);
    
    for(int i = 1; i<N; i+=2) {
        if(check[i] == 0) {
            long int b = atol(CH[i+1][1]);
            if(CH[i][0][0] == '+') {
                sum += b;
            } else if(CH[i][0][0] == '-'){
                sum -= b;
            } else {
                sum *= b;
            }
        }
    }   
    if(sum > MAX) {
        MAX = sum;
    }
    return;
}

void DFS() {
    calculate();

    for(int i = 1; i<M.size()-1; i += 2) {
        if(check[i] == 0) {
            check[i] = 2;
            long int a = atol(CH[i-1][1]);
            long int b = atol(CH[i+1][1]);
            long int sum = 0;

            if(CH[i][0][0] == '+')
                sum = a+b;
            else if(CH[i][0][0] == '*')
                sum = a*b;
            else if(CH[i][0][0] == '-')
                sum = a-b;
            
            
            if(checking(i)) {
                change(i, sum, 1);
                DFS();
                change(i, 0, 0);
            }
            check[i] = 0;
        }
    }
    return;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin.ignore();
    cin >> M;

    for(int i = 0; i<N; i++) {
        char* S = new char[21];
        S[0] = M.at(i);
        CH[i][0] = S;
        CH[i][1] = S;
    }

    DFS();
    cout << MAX << "\n";
    return 0;

}
