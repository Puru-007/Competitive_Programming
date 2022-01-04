//https://practice.geeksforgeeks.org/problems/gray-code-1611215248/1/#

#include<iostream>
#define vi vector<int>
#define pb push_back
#define sz() size()
#define NN v.size()
using namespace std;

//Best Optimal Solution in 0.2 time
//XOR the number itself with its 1 right shift to get its gray code

string convertToBinary (int n, int N) {
	vi v;
   	int temp = N;
   	while(temp) {
		v.pb(n & 1);
		n >>= 1;
		temp >>= 1;
	}
	string s = "";
	for(int i=v.size()-1; i>=0; i--){
		s += to_string(v[i]); 
	}
	return s;
}
   
vector<string> graycode(int n)   
{
	int N = (1 << (n-1));
    vector<string> v;
	for(int i=0; i<(N<<1); i++) {
    	int num1 = (i >> 1);
		int res = i ^ num1;
		string s = convertToBinary(res, (1 << (n-1)));
		v.push_back(s);
	}
	return v;
}
   
   
int main()
 {
	//call the fn
	return 0;
}


// Example 1:
// Input:
// N = 2
// Output: 
// 00 01 11 10
// Explanation: 
// 00 and 01 differ by one bit.
// 01 and 11 differ by one bit.
// 11 and 10 also differ by one bit.
 
// Example 2:
// Input:
// N=3
// Output:
// 000 001 011 010 110 111 101 100
// Explanation:
// 000 and 001 differ by one bit.
// 001 and 011 differ by one bit.
// 011 and 010 differ by one bit.
// Similarly, every successive pattern 
// differs by one bit.