//problem link: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

class Solution 
{
    public:
    bool isValid(int x, int y, vector<vector<bool>> &vis, int N){
        return min(x,y)>=0 && max(x,y)<N && vis[x][y]==0;
    }

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int steps=0;
	    int dir[9]={2,-1,2,1,-2,-1,-2,1,2};
	    vector<vector<bool>> vis(N,vector<bool>(N,0));
	    queue<pair<int,int>> q;
	    q.push({KnightPos[1]-1,KnightPos[0]-1});
	    vis[KnightPos[1]-1][KnightPos[0]-1]=1;
	    while(!q.empty()){
	        int sz=q.size();
	        while(sz--){
	            auto p=q.front();
	            q.pop();
	            int x=p.first, y=p.second;
	            if(x==TargetPos[1]-1 && y==TargetPos[0]-1){
	                return steps;
	            } 
	            for(int i=0;i<8;i++){
	                int nextX=x+dir[i], nextY=y+dir[i+1];
	                if(isValid(nextX,nextY,vis,N)){
	                    vis[nextX][nextY]=1;
	                    q.push({nextX,nextY});
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};