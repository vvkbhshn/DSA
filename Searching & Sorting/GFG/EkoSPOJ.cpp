//problem link: https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,l=0,r=0, res=-1;
	cin>>n>>m;
	vector<int> height(n);
	for(int i=0;i<n;i++){
		cin>>height[i];
		r=max(r,height[i]);
	}
	while(l<=r){
		int mid=l+(r-l)/2;
		long long cnt=0;
		for(int i=0;i<n;i++){
			if(height[i]>mid) cnt+=height[i]-mid;
		}
		if(cnt>=m){
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<res;
	return 0;
} 