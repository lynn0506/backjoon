#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
vector<vector<int> > relation(20001);
int Count = 5;
int answer = 0;
bool check = false;

void dfs(int str, vector<int> set) {
    if(check == true) {
        return;
    }
    if(set.size() ==  Count) {
        answer++;
        check = true;
        return;
    }
    for(int i = 0; i < relation[str].size(); i++) {
        if(!count(set.begin(), set.end(), relation[str][i])) {
            set.push_back(relation[str][i]);
            dfs(relation[str][i], set);
            set.pop_back();
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        if(relation[a].size() == 0) {
            vector<int> tt;
            tt.assign(1, b);
            relation[a] = tt;
        }
        else { 
            relation[a].push_back(b);
        }
        if(relation[b].size() == 0) {
            vector<int> tt;
            tt.assign(1, a);
            relation[b] = tt;
        } else {
            relation[b].push_back(a);
        }
    }
    for(int i = 0; i< N; i++) {
        vector<int> set;
        set.push_back(i);
        dfs(i, set);
        set.pop_back();
    }

    cout << answer << "\n";
}