#include <iostream> 
#include <string.h> 

using namespace std; 
int direc[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 0->북쪽, 1->동쪽, 2->남쪽 3->서쪽 
int N, M, r, c;
int cnt = 0;
int map[51][51] = {};
int visit[51][51] = {};

void clean(int r, int c, int d) {
    // for(int i = 0; i<N; i++) {
    //   for(int j = 0; j<M; j++) {
    //     cout << map[i][j] << " ";
    //   } cout << "\n";
    // } cout << "\n";

    if(map[r][c] == 0) {
      map[r][c] = 2;
      cnt++;
    }

    int xpos = r;
    int ypos = c;
    int next_d = d;

    for(int i=0; i<4; i++) {
      next_d = (next_d > 0) ? next_d-1 : 3; //왼쪽 방향 
      xpos = r + direc[next_d][0];
      ypos = c + direc[next_d][1];
      if(xpos >= 0 && xpos < N && ypos >= 0 && ypos < M && map[xpos][ypos] == 0) {
        clean(xpos, ypos, next_d);
        return;
      }
    }

    int back_d = (d >= 2) ? d-2 : d+2;
    xpos = r + direc[back_d][0];
    ypos = c + direc[back_d][1];

    if(xpos >= 0 && xpos < N && ypos >= 0 && ypos < M && map[xpos][ypos] != 1) {
      clean(xpos, ypos, d);
    }
    return;
}


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int d;
  cin >> N >> M;
  cin >> r >> c >> d;

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> map[i][j];
    }
  }
  clean(r, c, d);
  cout << cnt << endl;
  return 0;
}
