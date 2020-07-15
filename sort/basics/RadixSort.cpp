#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void countingSort(ll *arr,ll n,ll divisor) {
    ll ans[n],i;
    ll range[10] = {0};

    for(i=0;i<n;i++)
        range[(arr[i]/divisor)%10]++;
    
    for(i=1;i<10;i++)
        range[i] += range[i-1];

    for(i=n-1;i>=0;i--) {
        ans[range[(arr[i]/divisor)%10]-1] = arr[i];
        range[(arr[i]/divisor)%10]--;
    }

    for(i=0;i<n;i++)
        arr[i] = ans[i];
}


void radixSort(ll *arr,ll n) {
    ll i,d=0,x=1;
    ll maxElement = arr[0];
    for(i=1;i<n;i++)
        maxElement = max(maxElement, arr[i]);
    
    while(maxElement>0) {
        d++;
        maxElement /= 10;
    }

    for(i=1;i<=d;i++) {
        countingSort(arr,n,x);
        x *= 10;
    }
}

int main() {
    ll n,i;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    radixSort(arr,n);
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    

    return 0;
}