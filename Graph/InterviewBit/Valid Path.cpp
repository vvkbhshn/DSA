//problem link: https://www.interviewbit.com/problems/valid-path/

void markCirclePoints(int x, int y, int n, int r, vector<int> &A, vector<int> &B, vector<vector<int>> &vis){
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k=0;k<n;k++){
                if((A[k]-i)*(A[k]-i)+(B[k]-j)*(B[k]-j)<=r*r){
                    vis[i][j]=-1;
                    break;
                }
            }
        }
    }    
}

bool isValid(int i, int j, int x, int y){
    return i>=0 && i<=x && j>=0 && j<=y;
}

string Solution::solve(int x, int y, int n, int r, vector<int> &A, vector<int> &B) {
    vector<vector<int>> vis(101, vector<int>(101,0));
    markCirclePoints(x,y,n,r,A,B,vis);
    if(vis[0][0]==-1) return "NO";
    int dirX[8]={0,0,1,1,1,-1,-1,-1};
    int dirY[8]={-1,1,0,-1,1,0,-1,1};
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int i=p.first, j=p.second;
        if(i==x && j==y) return "YES";              
        for(int k=0;k<8;k++){
            int newX=i+dirX[k], newY=j+dirY[k];
            if(isValid(newX,newY,x,y) && vis[newX][newY]==0){
                q.push({newX,newY});
                vis[newX][newY]=1;
            }
        } 
    }
    return "NO";
}
