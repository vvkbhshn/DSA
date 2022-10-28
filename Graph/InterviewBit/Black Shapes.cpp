//problem link: https://www.interviewbit.com/problems/black-shapes/

void dfs(int x, int y, int n, int m, vector<string> &A){
    if(x<0 || x>=n || y<0 || y>=m || A[x][y]!='X') return;
    A[x][y]='Y';
    dfs(x+1,y,n,m,A);
    dfs(x-1,y,n,m,A);
    dfs(x,y-1,n,m,A);
    dfs(x,y+1,n,m,A);
}

int Solution::black(vector<string> &A) {
    int n=A.size(), m=A[0].size();
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='X'){
                dfs(i,j,n,m,A);
                res++;
            }
        }
    }
    return res;
}
