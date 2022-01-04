#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int N)
    {
        int count = 0;
        int maxCount = 0;
        while(N && 1) {
            if(N & 1) {
                count++;
                maxCount = max(maxCount, count);
            }
            
            else{
                count = 0;
            }
            N >>= 1;
        }
        return maxCount;
}

int main () {
    cout<<maxConsecutiveOnes(7);
}


// OP - 3
// Input: N = 14
// Output: 3
// Explanation: 
// Binary representation of 14 is 
// 1110, in which 111 is the longest 
// consecutive set bits of length is 3.