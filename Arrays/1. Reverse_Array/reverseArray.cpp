#include<bits/stdc++.h>
using namespace std;

void swapElements(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void reverseArray(int arr[], int N){
    for(int i=0; i < N/2; i++){
        swapElements(&arr[i], &arr[N-i-1]);
    }
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    reverseArray(arr, N);
    for(int i=0; i<N; i++){
        cout<<arr[i];
    }
}