// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	
	for(int i=3; i<=n; i++){
	    table[i] += table[i-3];
	}
	
	for(int i=5; i<=n; i++){
	    table[i] += table[i-5];
	}
	
	for(int i=10; i<=n; i++){
	    table[i] += table[i-10];
	}
	
	return table[n];
	
	
	
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends




// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Example:
// Input
// 3
// 8
// 20
// 13
// Output
// 1
// 4
// 2
// Explanation
// For 1st example when n = 8
// { 3, 5 } and {5, 3} are the 
// two possible permutations but 
// these represent the same 
// cobmination. Hence output is 1.