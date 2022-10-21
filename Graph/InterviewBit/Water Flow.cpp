//problem link: https://www.interviewbit.com/problems/water-flow/

int dir[5]={1,0,-1,0,1};

void dfs(int x, int y, vector<vector<int>> &A, vector<vector<int>> &vis, int flag){
    if(vis[x][y]>0) vis[x][y]=flag+1;
    else vis[x][y]=flag;
    for(int i=0;i<4;i++){
        int X=x+dir[i], Y=y+dir[i+1];
        if(X>=0 && X<A.size() && Y>=0 && Y<A[0].size() && vis[X][Y]<flag && A[X][Y]>=A[x][y]) dfs(X,Y,A,vis,flag);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(), m=A[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++) if(vis[i][0]<1) dfs(i,0,A,vis,1);
    for(int j=1;j<m;j++) if(vis[0][j]<1) dfs(0,j,A,vis,1);
    for(int i=0;i<n;i++) if(vis[i][m-1]<2) dfs(i,m-1,A,vis,2);
    for(int j=0;j<m-1;j++) if(vis[n-1][j]<2) dfs(n-1,j,A,vis,2);
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==3) res++;
        }
    }
    return res;
}