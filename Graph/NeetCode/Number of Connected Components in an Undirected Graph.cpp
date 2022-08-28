//problem link: https://www.codechef.com/problems/CC

#include <bits/stdc++.h>
using namespace std;

int doFind(int x, vector<int> &parent){
    if(x!=parent[x]) parent[x]=doFind(parent[x],parent);
    return parent[x];
}

void doUnion(int x, int y, vector<int> &parent, vector<int> &rank){
    if(rank[x]<rank[y]) parent[x]=y;
    else if(rank[y]<rank[x]) parent[y]=x;
    else{
        parent[y]=x;
        rank[x]++;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    int components=n;
	    vector<int> parent(n), rank(n,0);
	    for(int i=0;i<n;i++) parent[i]=i;
	    for(int i=0;i<e;i++){
	        int u,v;
	        cin>>u>>v;
	        int x=doFind(u,parent), y=doFind(v,parent);
	        if(x!=y){
	            doUnion(x,y,parent,rank);
	            components--;
	        }
	    }
	    cout<<components<<'\n';
	}
	return 0;
}