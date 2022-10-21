//problem link: https://www.interviewbit.com/problems/word-search-board/

int dir[5]={1,0,-1,0,1};

bool isValid(vector<string> &A, int x, int y){
    return x>=0 && x<A.size() && y>=0 && y<A[0].length();
}

bool dfs(vector<string> &A, string &B, int x, int y, int index){
    if(index==B.length()) return true;
    for(int i=0;i<4;i++){
        int x2=x+dir[i], y2=y+dir[i+1];
        if(isValid(A,x2,y2) && A[x2][y2]==B[index] && dfs(A,B,x2,y2,index+1)) return true; 
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    int n=A.size(), m=A[0].length();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==B[0] && dfs(A,B,i,j,1)) return 1;
        }
    }
    return 0;
}
