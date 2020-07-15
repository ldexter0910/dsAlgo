#include<bits/stdc++.h>
using namespace std;

#define ll long long int

/* 1-maxElement -> 0-maxElement-1 */

void countingSort(ll *arr,ll n,ll *ans) {
    ll i, maxElement;
    
    maxElement = arr[0];
    for(i=1;i<n;i++)
        maxElement = max(maxElement, arr[i]);
    // cout<<maxElement<<"\n";

    ll a[maxElement] = {0};
    for(i=0;i<n;i++)
        a[arr[i]-1]++;
    
    // for(i=0;i<maxElement;i++)
    //     cout<<a[i]<<" ";
    // cout<<"\n";

    for(i=1;i<maxElement;i++)
        a[i] += a[i-1];

    // for(i=0;i<maxElement;i++)
    //     cout<<a[i]<<" ";
    // cout<<"\n";

    for(i=0;i<n;i++) {
        ans[a[arr[i]-1]-1] = arr[i];
        --a[arr[i]-1];
    }
}

int main() {

    ll n,i;
    cin>>n;
    ll arr[n], ans[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    
    countingSort(arr,n,ans);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}