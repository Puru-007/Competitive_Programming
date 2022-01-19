#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    
        vector<pair<double, double>> ratio;
        for(int i=0; i<n; i++) {
            double div = (double)(arr[i].value)/(double)(arr[i].weight);
            ratio.push_back(make_pair(div, arr[i].weight));
        }
        
        sort(ratio.begin(), ratio.end());
        
        int totalW = 0;
        double maxVal = 0;
        int i=n-1;
        int flag = 1;
        while(flag && i>=0) {
            totalW += ratio[i].second;
            maxVal += (ratio[i].first * ratio[i].second);
            if(totalW > W) {
                flag = 0;
                totalW -= ratio[i].second;
                maxVal -= (ratio[i].first * ratio[i].second);
                break;
            }
            i--;
        }
        
        if(flag == 0) {
            // i-=1;
            maxVal += ((W - totalW) * (ratio[i].first));
        }
        return maxVal;
    }
        
};



int main()
{
	int t;

	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];

		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		

		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  