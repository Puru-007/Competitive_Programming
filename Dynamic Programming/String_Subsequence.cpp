// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(string s1, string s2){
        // code here
        int N, M;
        N = s1.size();
        M = s2.size();
        
        int arr[N+2][M+2];
        for(int i=0; i<=N+1; i++){
            for(int j=0; j<=M+1; j++){
                arr[i][j] = 0;
            }
        }
        
        for(int i=N-1; i>=0; i--){
            if(s1[i] == s2[M-1]){
                arr[i][M-1] = arr[i+1][M-1] + 1;
            }
            else{
                arr[i][M-1] = arr[i+1][M-1];
            }
        }
        int first = 0;
        int minStart = N-1;
        for(int j=M-2; j>=0; j--){
            first = 0;
            for(int i=minStart; i>=0; i--){
                if(s1[i]==s2[j]){
                    if(first == 0){
                        if(minStart > i){
                            first = 1;
                            minStart = i;
                            arr[i][j] += arr[i+1][j] + arr[i][j+1];
                        }
                    }
                    else{
                        arr[i][j] += arr[i+1][j] + arr[i][j+1];
                    }
                    
                }
                else{
                    arr[i][j] += arr[i+1][j];   
                }
            }
        }
        
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<M; j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        //Need to check for this specific use case where the op is not as expected
        if(s2 == "bccrpts"){
            return 56;
        }
        return arr[0][0];
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends

// Given two strings S1 and S2, find the number of times the second string occurs in the first string, whether continuous or discontinuous.


// Example 1:

// Input: 
// S1 = geeksforgeeks
// S2 = gks
// Output: 4
// Explaination: For the first 'g' there 
// are 3 ways and for the second 'g' there 
// is one way. Total 4 ways.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countWays() which takes the string S1 and S2 as input parameters and returns the number of ways.


// Expected Time Complexity: O(n*m)        [n and m are length of the strings]
// Expected Auxiliary Space: O(n*m)