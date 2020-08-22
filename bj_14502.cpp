#include <iostream> 
#include <algorithm> 
#include <utility> 
#include <map> 
#include <stack> 
#include <queue> 
#include <string> 
#include <cstdlib>
#include <vector> 
#include <climits> 
#include <cmath>

using namespace std;

int box[10][10] = {};
int fake[10][10] = {};

int N, M;
int direc[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int> > virus;
vector<pair<int, int> > empty;
int answer = 0;

void wall(pair<int, int> target) {
    box[target.first][target.second] = !box[target.first][target.second];
}

void dfs(pair<int, int> vi) {
    for(int i = 0; i<4; i++) {
        int posx = direc[i][0] + vi.first;
        int posy = direc[i][1] + vi.second;

        if(posx >= 0 && posx < N && posy >= 0 && posy < M) {
            if(fake[posx][posy] == 0) {
                fake[posx][posy] = 2;
                dfs(make_pair(posx, posy));
            }
        }
    }
}

void virus_spread() {
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            fake[i][j] = box[i][j];
        }
    }

    for(int i = 0; i<virus.size(); i++) {
        pair<int, int> vi = virus[i];
        dfs(vi);
    }

    int count = 0;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            if(fake[i][j] == 0)
                count++;
        }
    }
    answer = max(count, answer);
}


void solution(int N, int M) {
    int siz = empty.size();
    for(int i = 0; i<siz-2; i++) {
        for(int j = i+1; j<siz-1; j++) {
            for(int k = j+1; k<siz; k++) {
                pair<int, int> one = empty[i];
                pair<int, int> two = empty[j];
                pair<int, int> three = empty[k];

                wall(one);
                wall(two);
                wall(three);

                virus_spread();

                wall(one);
                wall(two);
                wall(three);
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 0) 
                empty.push_back(make_pair(i, j));
            
            if(box[i][j] == 2) 
                virus.push_back(make_pair(i, j));
        }
    }
    solution(N, M);
    cout << answer << endl;
}
