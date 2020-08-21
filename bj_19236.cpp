#include <iostream> 
#include <utility>

using namespace std;


// 방향 설정 -> 8개 가능 
int direc[9][2] =  {
	{0, 0}, {-1, 0}, {-1, -1}, 
	{0, -1}, {1, -1}, {1, 0}, 
	{1, 1}, {0, 1}, {-1, 1}
};

// first = x pos, second = y pos
pair<int, int> currPos[17] = {};

// first = 몇 번째인지, second = 방향 
pair<int, int> box[4][4] = {};
int maxVal = 0;


void solve(int x, int y, int sum) {
	int num = box[x][y].first;
	int dir = box[x][y].second;

	// 합을 구한다. 
	sum += num;

	// for(int i=0; i<4; i++) {
	// 	for(int l=0; l<4; l++) {
	// 		cout << "(" << box[i][l].first << " " << box[i][l].second << ") ";
	// 	}
	// 	cout << "\n";
	// } cout << "\n";
	maxVal = max(sum, maxVal);

	//num 현재 위치는 이미 방문했기 때문에 다시 못가도록 설정한다 
	currPos[num] = make_pair(-1, -1);
	box[x][y] = make_pair(-1, -1); 

	for(int i = 1; i<=16; i++) {
		if(currPos[i] == make_pair(-1, -1)) continue;

		int j = 1;
		int xpos, ypos = 0; 
		int currX = currPos[i].first;
		int currY = currPos[i].second;
		int newd = box[currX][currY].second;

		// for(int e=0; e<4; e++) {
		// 	for(int l=0; l<4; l++) {
		// 		cout << "(" << box[e][l].first << " " << box[e][l].second << ") ";
		// 	} cout << "\n";
		// } cout << "\n";
		

		for(j = 1; j<= 8; j++) {
			xpos = currX + direc[newd][0];
			ypos = currY + direc[newd][1];

			if((xpos < 0 || xpos >=4 || ypos < 0 || ypos >= 4) || (xpos == x && ypos == y)) {
				newd += 1;
				if(newd == 9) newd = 1;
				continue; //맞는 칸인 경우 선택받음!!! 
			} else { 
				break;
			}
		}

		if(j > 8) continue;
		if(box[xpos][ypos].first != -1) 
			currPos[box[xpos][ypos].first] = make_pair(currPos[i].first, currPos[i].second);

		currPos[i] = make_pair(xpos, ypos);
		pair<int, int> ret = box[xpos][ypos];

		box[xpos][ypos] = make_pair(box[currX][currY].first, newd);
		box[currX][currY] = ret;
	}
	pair<int, int> sharkbox[4][4] = {};
	pair<int, int> sharkpos[17] = {};

	for(int i = 0; i<4; i++) {
		for(int k = 0; k<4; k++) {
			sharkbox[i][k] = box[i][k];
		}
	}

	for(int i = 1; i<=16; i++) 
		sharkpos[i] = currPos[i];

	int shx = x;
	int shy = y;

	for(int i = 0; i<3; i++) {
		shx += direc[dir][0];
		shy += direc[dir][1];

		if(shx < 0 || shx >= 4|| shy < 0 || shy >= 4) break;
		if(box[shx][shy].first == -1) continue;
		solve(shx, shy, sum);

		for(int k = 0; k<4; k++) {
			for(int m = 0; m<4; m++) {
				box[k][m] = sharkbox[k][m];
			}
		}

		for(int k = 1; k<=16; k++) 
			currPos[k] = sharkpos[k];
	}

}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b;

	int posx, posy;
	currPos[0] = make_pair(0, 0);

	for(int i = 0; i<4; i++) {
		for(int j = 0; j<4; j++) {
			cin >> a;
			cin >> b;

			currPos[a] = make_pair(i, j);
			box[i][j] = make_pair(a, b);
		}
	}


	solve(0, 0, 0);
	cout << maxVal << endl;
}





