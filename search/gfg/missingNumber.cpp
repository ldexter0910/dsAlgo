// You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
// Example: 

// Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
// Output: 5
// Explanation: The missing number from 1 to 8 is 5

// Input: arr[] = {1, 2, 3, 5}
// Output: 4
// Explanation: The missing number from 1 to 5 is 4

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,i,x;
    ll xorAll = 0, xorElements = 0;
    cin>>n;
    for(i=0;i<n-1;i++) {
        cin>>x;
        xorAll = xorAll ^ (i+1);
        xorElements ^= x;
    }
    xorAll = xorAll ^ (i+1);
    cout<<(xorElements ^ xorAll)<<"\n";
    
    return 0;
}