//problem link: https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;

int findMinGap(int arr[], int n, int c){
    int lo=1, hi=arr[n-1]-arr[0], mid;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        int cnt=1, curr=0;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[curr]>=mid){
                cnt++;
                curr=i;
            }
        }
        if(cnt>=c) lo=mid+1;
        else hi=mid-1;
    }
    return hi;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        cout<<findMinGap(arr, n, c)<<'\n';
    }
}