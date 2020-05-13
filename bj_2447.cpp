#include <iostream>
#include <algorithm> 
#include <string.h>

using namespace std;
int N;
int star[10000][10000] = { };


void make_blank(int x, int y, int siz) {
    for(int i = x; i<x+siz; i++) {
        for(int j = y; j<y+siz; j++) {
            star[i][j] = 1;
        }
    }
}
void cover(int x, int y, int siz) {
    if(siz == 3) {
        star[x+1][y+1] = 1;
        return;
    } else {
        make_blank(x + siz/3, y + siz/3, siz/3);
        cover(x, y, siz/3);
        cover(x, y+ siz/3, siz/3);
        cover(x, y+ siz*2/3, siz/3);
        cover(x + siz/3, y, siz/3);
        cover(x + siz/3, y+ siz*2/3, siz/3);
        cover(x+siz*2/3, y, siz/3);
        cover(x+siz*2/3, y + siz/3, siz/3);
        cover(x+siz*2/3, y+siz*2/3, siz/3);
    }

}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
        
    int N;
    cin >> N;

    for(int i = 0; i<N; i++)  
        memset(star[i], 0, sizeof(star[i]));
    
    cover(0, 0, N);
    
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            if(star[i][j] == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

}