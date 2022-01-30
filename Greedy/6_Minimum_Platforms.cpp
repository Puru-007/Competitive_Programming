// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	vector<pair<int, char>> vec;
    	for(int i=0; i<n; i++){
    	    vec.push_back(make_pair(arr[i], 'A'));
    	}
    	for(int i=0; i<n; i++){
    	    vec.push_back(make_pair(dep[i], 'D'));
    	}
    	sort(vec.begin(), vec.end());
    	int platforms = 0;
    	int maxPlat = INT_MIN;
    	for(int i=0; i<vec.size(); i++){
    	    if(vec[i].second == 'A'){
    	        platforms += 1;
    	        if(platforms > maxPlat){
    	            maxPlat = platforms;
    	        }
    	    }
    	    else{
    	        platforms -= 1;
    	    }
    	}
    	return maxPlat;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}

// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// Example 1:

// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation: 
// Minimum 3 platforms are required to 
// safely arrive and depart all trains.
// Example 2:

// Input: n = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to 
// safely manage the arrival and departure 
// of all trains. 