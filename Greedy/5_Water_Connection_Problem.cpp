#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        int myArr[n][2];
    	for(int i=1; i<=n; i++){
    	    for(int j=1; j<=2; j++){
    	        myArr[i][j] = 0;
    	    }
    	}
    	
    	for(int i=0; i<p; i++){
    	    myArr[a[i]][1] = 1;
    	}
    	
    	for(int i=0; i<p; i++){
    	    myArr[b[i]][2] = 1;
    	}
    	
    	int start[n];
    	int dia[n];
    	
    	for(int i=1; i<=n; i++){
    	    start[i] = 0;
    	    dia[i] = 0;
    	}
    	
    	for(int i=0; i<p; i++){
    	    start[a[i]] = b[i];
    	    dia[a[i]] = d[i];
    	}
    	
    	int count = 0;
    	vector<int> myVec;
    	for(int i=1; i<=n; i++){
    	    if(myArr[i][2] == 0 && myArr[i][1] == 1){
    	        count+=1;
    	        myVec.push_back(i);
    	    }
    	}
    	
    // 	int res[count][3];
    	vector<vector<int>> res;
    	for(int i=0; i<count; i++){
    	    vector<int> temp;
    	    for(int j=0; j<3; j++){
    	        temp.push_back(0);
    	    }
    	    res.push_back(temp);
    	}
    	
    	for(int i=0; i<count; i++){
    	    int num = myVec[i];
    	    res[i][0] = num;
    	    int minDia = 100009;
    	    int loop = 0;
    	    
    	    while(start[num] != 0 && (loop < n+1)) {
    	       // minDia = 100009;
    	        if(minDia > dia[num]) {
    	           // res[i][2] = minDia;
    	            minDia = dia[num];
    	        }
    	        num = start[num];
    	        loop += 1;
    	        
    	    }
    	    res[i][1] = num;
    	    res[i][2] = minDia;
    	    
    	}
	    return res;
    }
};


int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
} 

// https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1#
// Example 1:

// Input:
// n = 9, p = 6
// a[] = {7,5,4,2,9,3}
// b[] = {4,9,6,8,7,1}
// d[] = {98,72,10,22,17,66} 
// Output: 
// 3
// 2 8 22
// 3 1 66
// 5 6 10
// Explanation:
// Connected components are 
// 3->1, 5->9->7->4->6 and 2->8.
// Therefore, our answer is 3 
// followed by 2 8 22, 3 1 66, 5 6 10.