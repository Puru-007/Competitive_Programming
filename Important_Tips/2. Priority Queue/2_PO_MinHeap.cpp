#include <bits/stdc++.h>
using namespace std;

bool sortMax(int num1, int num2){
    return num1 > num2;
}

int main() {
	// your code goes here
	int N;
	cin>>N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<N; i++) {
	    int num;
	    cin>>num;
	    pq.push(num);
	}
	
	while(pq.size() != 0) {
	    cout<<pq.top()<<" ";
	    pq.pop();
	}
	return 0;
}
