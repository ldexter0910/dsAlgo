// Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

// Input:
// The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.

// Output:
// Corresponding to each test case, output the index of the element found in the array.  If element is not present, then output -1.

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ N ≤ 107
// 0 ≤ Ai ≤ 108
// 1 ≤ K ≤ 108

// Example:
// Input:
// 3
// 9
// 5 6 7 8 9 10 1 2 3
// 10
// 3
// 3 1 2
// 1
// 4
// 3 5 1 2
// 6

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll binarySearch(vector<ll> &arr, ll low, ll high, ll x) {
    ll mid;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

ll searchRotatedIndex(vector<ll> &arr, ll n) {
    ll low, high, mid, ans = -1;
    low = 0;
    high = n-1;
    while(low <= high) {
        mid = low + (high-low)/2;
        if(arr[mid] <= arr[n-1]) {
            ans = mid;
            high = mid-1;
        } else
            low = mid+1;
    }
    return ans;
}

ll search(vector<ll> &arr, ll &n, ll &x) {
    ll ans = -1;
    ll rotatedIndex = searchRotatedIndex(arr, n);
    if(rotatedIndex == 0)
        ans = binarySearch(arr,0,n-1,x);
    else {
        ans = binarySearch(arr,0,rotatedIndex-1,x);
        ans = (ans != -1) ? ans : binarySearch(arr,rotatedIndex,n-1,x);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--) {
        ll i, n, x;
        cin>>n;
        vector<ll> arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;

        cout<<search(arr, n, x)<<"\n";
    }

    return 0;
}