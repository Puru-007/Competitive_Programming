#include<bits/stdc++.h>
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

int dfs(vvi &arr, vvi &visited, int x, int y, int N, int M){
    if(x >= 0 && y >= 0 && x < N && y < M){
        if(arr[x][y]){
            if(!visited[x][y]){
                visited[x][y] = 1;
                return 1 + dfs(arr, visited, x+1, y, N, M) + dfs(arr, visited, x-1, y, N, M) + dfs(arr, visited, x, y-1, N, M) + dfs(arr, visited, x, y+1, N, M) + dfs(arr, visited, x-1, y-1, N, M) + dfs(arr, visited, x-1, y+1, N, M) + dfs(arr, visited, x+1, y-1, N, M) + dfs(arr, visited, x+1, y+1, N, M);
            }
        }
    }
    return 0;
}

void solve() {
    int N, M;
    cin>>N>>M;
    vvi arr;
    vvi visited;
    for(int i=0; i<N; i++){
        vi temp;
        vi vis;
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            temp.pb(s[j] - '0');
            vis.pb(0);
        }
        arr.pb(temp);
        visited.pb(vis);
    }
    int maxSum = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]){
                if(!visited[i][j]){
                    int sum = dfs(arr, visited, i, j, N, M);
                    if(sum > maxSum){
                        maxSum = sum;
                    }
                }
            }
        }
        
    }
    if(maxSum == -1){
        cout<<0<<endl;
        return;
    }
    cout<<maxSum<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    // int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    // for (int t = 1; t <= tc; t++) {
    //     // cout << "Case #" << t << ": ";
    //     solve();
    // }
}

// Geek has a rosarium and it has N*M slots, some of them are empty and some of them have roses. Given N*M character array consists of 0's and 1's. 0 represents an empty spot and 1 represents a rose. The task is to find the maximum number of adjacent roses in geek's rosarium. For a spot (i, j) adjacent spots are (i+1, j), (i-1, j), (i, j-1), (i, j+1), (i-1, j-1), (i-1, j+1), (i+1, j-1),  and (i+1, j+1).

// Input:
// 1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// 2. The first line of each test case contains two space-separated integers N and M.
// 3. Next N lines consist of M characters.

// Output: For each test case, print the maximum number of adjacent roses.

// Constraints:
// 1. 1 <= T <= 100
// 2. 1 <= N, M <= 100
// 3. '0' <= arr[i][j] <= '1'

// Example:
// Input:
// 2
// 2 2
// 10
// 01
// 3 4
// 1001
// 0011
// 0101

// Output:
// 2
// 5


