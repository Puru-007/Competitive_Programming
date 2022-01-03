#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

unsigned int reverseBits(unsigned int n)
    {
        //by >> & bitwise
        int num = 0;
        while(n && 1){
            if(n & 1){
                num <<= 1;
                num += 1;
            }
            else{
                (num <<= 1);
            }
            // cout<<num;
            n >>= 1;
        }
        return num;
    
        
        
        //normal bitwise
        // vi v;
        // while(n > 0){
        //     v.pb(n%2);
        //     n /= 2;
        // }
        // int res = 0;
        // int N = v.size();
        // for(int i=0; i<N; i++){
        //     res += (v[N-i-1]*(1<<i));
        //     // cout<<v[N-i-1]" -> "<<res<<endl;
        // }
        // return res;
    }

int main() {
    cout<<reverseBits(11);
	return 0;
}

// Input : 
// N = 11
// Output:
// 13
// Explanation:
// (11)10 = (1011)2.
// After reversing the bits we get:
// (1101)2 = (13)10.