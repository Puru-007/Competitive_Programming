#include<iostream>
using namespace std;

int noOfSet1Bits (int N) {
    int count = 0;
        while(N && 1) {
            if(N & 1) {
                count++;
            }
            N >>= 1;
        }
        return count;
}

int main() {
    cout<<noOfSet1Bits(6);
    return 0;
}

// Input:
// N = 6
// Output:
// 2
// Explanation:
// Binary representation is '110' 
// So the count of the set bit is 2.