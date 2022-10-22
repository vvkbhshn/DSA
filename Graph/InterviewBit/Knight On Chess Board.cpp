//problem link: https://www.interviewbit.com/problems/knight-on-chess-board/

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<bool>> vis(A+1,vector<bool>(B+1,false));
    queue<pair<int,int>> q;
    q.push({C,D});
    vis[C][D]=true;
    int moves=0;
    int dirX[8]={-2,-2,-1,-1,1,1,2,2};
    int dirY[8]={-1,1,-2,2,-2,2,-1,1};
    while(!q.empty()){
        int n=q.size();
        while(n--){
            auto p=q.front();
            q.pop();
            if(p.first==E && p.second==F) return moves;
            for(int i=0;i<8;i++){
                int x=p.first+dirX[i], y=p.second+dirY[i];
                if(x>0 && x<=A && y>0 && y<=B && !vis[x][y]){
                    q.push({x,y});
                    vis[x][y]=true;
                }
            }
        }
        moves++;
    }
    return -1;
}