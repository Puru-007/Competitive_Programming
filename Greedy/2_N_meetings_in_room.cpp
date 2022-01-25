#include <bits/stdc++.h>
using namespace std;

static bool sortByEndTime (pair<int, int> a, pair<int, int> b) {
    return (a.second < b.second);
}

int maxMeetings(int start[], int end[], int n){
    if(n == 1) {
        return 1;
    }
    vector<pair<int, int>> meets;
    for(int i=0; i<n; i++) {
        meets.push_back(make_pair(start[i], end[i]));
    }
    sort(meets.begin(), meets.end(), sortByEndTime);        

    int count = 0;
    int curr = 0;
    for(int i=0; i<meets.size(); i++) {
        if(meets[i].first > curr) {
            count++;
            curr = meets[i].second;
        }
    }
    return count;
}

int main() {
    int N;
    cin>>N;
    int start[N];
    int end[N];

    for(int i=0; i<N; i++){
        cin>>start[i];
    }

    for(int i=0; i<N; i++) {
        cin>>end[i];
    }

    cout<<maxMeetings(start, end, N);
}


//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


// Example 1:

// Input:
// N = 6
// start[] = {1,3,0,5,8,5}
// end[] =  {2,4,6,7,9,9}
// Output: 
// 4
// Explanation:
// Maximum four meetings can be held with
// given start and end timings.
// The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
// Example 2:

// Input:
// N = 3
// start[] = {10, 12, 20}
// end[] = {20, 25, 30}
// Output: 
// 1
// Explanation:
// Only one meetings can be held
// with given start and end timings.

// Your Task :
// You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


// Expected Time Complexity : O(N*LogN)
// Expected Auxilliary Space : O(N)

