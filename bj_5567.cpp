#include <iostream>
#include <vector>
#include <algorithm>
/** 꼭꼭 다시 풀기 **/

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> friends[501];

    for(int i = 0; i< M; i++) {
        int ret1, ret2;
        cin >> ret1 >> ret2;

        vector<int> tmp = friends[ret1];
        tmp.push_back(ret2);
        friends[ret1] = tmp;

        vector<int> tmp2 = friends[ret2];
        tmp2.push_back(ret1);
        friends[ret2] = tmp2;
    }
    vector<int> list;
    
    for(int i = 0; i<friends[1].size(); i++) {
        int person = friends[1].at(i);
        list.push_back(person);

        for(int j = 0; j<friends[person].size(); j++) {
            int ret = friends[person].at(j);
            if(ret != 1) 
                list.push_back(ret);
        }
    }
   
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());

    cout << list.size() << endl;

}