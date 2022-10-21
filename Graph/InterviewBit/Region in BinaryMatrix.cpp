//problem link: https://www.interviewbit.com/problems/region-in-binarymatrix/

int Solution::solve(vector<vector<int>> &A) {
    int n=A.size(), m=A[0].size();
    int res=0;
    int dirX[8]={0,0,-1,-1,-1,1,1,1};
    int dirY[8]={-1,1,-1,0,1,-1,0,1};    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1){
                int area=0;
                queue<pair<int,int>> q;
                q.push({i,j});
                A[i][j]=0;
                while(!q.empty()){
                    auto p=q.front();
                    q.pop();
                    area++;
                    for(int k=0;k<8;k++){
                        int x=p.first+dirX[k], y=p.second+dirY[k];
                        if(x>=0 && x<n && y>=0 && y<m && A[x][y]==1){
                            q.push({x,y});
                            A[x][y]=0;
                        }
                    }
                }
                res=max(res,area);
            }
        }
    }
    return res;
}