//problem link: https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,q,sum=0;
	cin>>n;
	int power[n], prefSum[n];
	for(int i=0;i<n;i++) cin>>power[i];
	sort(power,power+n);	
	for(int i=0;i<n;i++){
		sum+=power[i];
		prefSum[i]=sum;
	}	
	cin>>q;
	while(q--){
		int p;
		cin>>p;
		if(p<power[0]){
			cout<<0<<" "<<0<<'\n';
			continue;
		}
		if(p>=power[n-1]){
			cout<<n<<" "<<prefSum[n-1]<<'\n';
			continue;
		}
		int l=0, r=n-1, idx=-1;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(power[mid]<=p){
				idx=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<idx+1<<" "<<prefSum[idx]<<'\n';
	}
}

