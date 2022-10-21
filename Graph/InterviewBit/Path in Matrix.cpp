//problem link: https://www.interviewbit.com/problems/path-in-matrix/

bool dfs(int x, int y, int finalX, int finalY, vector<vector<int>> &A){
    if(min(x,y)<0 || max(x,y)>=A.size() || A[x][y]==0) return false;
    A[x][y]=0;
    if(x==finalX && y==finalY) return true;
    return dfs(x+1,y,finalX,finalY,A) || dfs(x-1,y,finalX,finalY,A) || dfs(x,y+1,finalX,finalY,A) || dfs(x,y-1,finalX,finalY,A);
}

int Solution::checkPath(vector<vector<int>> &A) {
    int n=A.size();
    pair<int,int> src, dest;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==1) src={i,j};
            else if(A[i][j]==2) dest={i,j};
        }
    }
    return dfs(src.first,src.second,dest.first,dest.second,A);
}