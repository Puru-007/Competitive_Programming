#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int main() {
    int arr[] = {5, 3, 6, 1, 2, 4};
    int arr1[] = {100, 500, 300, 200, 600, 400};

    vector<pair<int, int>> vec;
    for(int i=0; i<6; i++) {
        // vec.pb(make_pair(arr[i], arr1[i]));
        vec.pb(mp(arr[i], arr1[i]));
    }

    sort(vec.begin(), vec.end());
    for(int i=0; i<6; i++) {
        cout<<vec[i].first<<"->"<<vec[i].second<<endl;
    }
}