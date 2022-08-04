//problem link: https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int l=1, r=arr[n-1]-arr[0], res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int cnt=0, curr=0;
            for(int i=1;i<n;i++){
                if(arr[i]-arr[curr]>=mid){
                    curr=i;
                    cnt++;
                }
            }
            cnt++; //for last cow
            if(cnt>=c) l=mid+1;
            else r=mid-1;
        }
        cout<<r<<'\n';
    }
} 