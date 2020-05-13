#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <climits>
#include <set>

using namespace std;

int main() {
  int N;
  long long asn = 0;
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;

  int arr[100002] = {};
  long dp[100002][2] = {};
  int Max = INT_MIN;

  for(int i = 0; i<N; i++) {
     cin >> arr[i];
     dp[i][0] = arr[i];
     if(arr[i] > Max)
       Max = arr[i];
  }

  if(dp[0][0] < Max)
    dp[0][1] = 0;
  else 
    dp[0][1] = dp[0][0];

  for(int j = 0; j<N-1; j++) {
    dp[j+1][1] = max(max((dp[j][1] + dp[j+1][0]), dp[j][0]), dp[j+1][0]);
  }

  cout << dp[N-1][1] << "\n";
  return 0;
}
