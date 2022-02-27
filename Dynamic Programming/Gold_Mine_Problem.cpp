#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mk make_pair
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int EPS = 1e-9;

int recurMaxGold (int i, int j, int N, int M, vvi &goldArr, vvi arr){
      if(i < 0 || i == N || j == M){
            return 0;
      }
      if(goldArr[i][j] != -1){
            return goldArr[i][j];
      }
      return goldArr[i][j] = arr[i][j] + max(recurMaxGold(i-1, j+1, N, M, goldArr, arr), max(recurMaxGold(i+1, j+1, N, M, goldArr, arr), recurMaxGold(i, j+1, N, M, goldArr, arr)));

    }

int maxGold(int N, int M, vvi arr){
      vvi goldArr(N, vi (M, -1));
      int res = 0;
      for(int i=0; i<N; i++){
            res = max(res, recurMaxGold(i, 0, N, M, goldArr, arr));
      }
      // for(int i=0; i<N; i++){
      //       for(int j=0; j<M; j++){
      //             cout<<goldArr[i][j]<<" ";
      //             if(res < goldArr[i][j]){
                        
      //                   res = goldArr[i][j];
      //             }
      //       }
      //       cout<<endl;
      // }
      return res;
}


void solve() {
      int n, m;
      cin>>n>>m;
      vvi M (n, vi(m, 0));
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin>>M[i][j];
            }
      }
      cout<<maxGold(n, m, M)<<endl;
}

int32_t main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	      solve();
	}
	return 0;
}




// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

// to the cell diagonally up towards the right 
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.


// Example 1:

// Input: n = 3, m = 3
// M = {{1, 3, 3},
//      {2, 1, 4},
//      {0, 6, 4}};
// Output: 12
// Explaination: 
// The path is {(1,0) -> (2,1) -> (2,2)}.

// Example 2:

// Input: n = 4, m = 4
// M = {{1, 3, 1, 5},
//      {2, 2, 4, 1},
//      {5, 0, 2, 3},
//      {0, 6, 1, 2}};
// Output: 16
// Explaination: 
// The path is {(2,0) -> (3,1) -> (2,2) 
// -> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
// -> (0,3)}.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function maxGold() which takes the values n, m and the mine M as input parameters and returns the maximum amount of gold that can be collected.


// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)