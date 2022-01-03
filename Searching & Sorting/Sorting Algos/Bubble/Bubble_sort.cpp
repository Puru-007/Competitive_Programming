#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int N){
    int ele = 0;
    bool swapped = false;
	while(ele < N){
	    for(int i=0; i<N-1-ele; i++){
	        if(arr[i] > arr[i+1]){
	            int temp = arr[i];
	            arr[i] = arr[i+1];
	            arr[i+1] = temp;
	            swapped = true;
	        }
	    }
	    ele++;
	    if(swapped == false){
	        break;
	    }
	}
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    bubbleSort(arr, N);
	
	for(int i=0; i<N; i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
