//problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:    
    int del[5]={-1,0,1,0,-1};
    char dir[4]={'U','R','D','L'};
    
    bool isValid(int x, int y, vector<vector<int>> &m ,int n){
        return min(x,y)>=0 && max(x,y)<n && m[x][y]==1;
    }
    
    void dfs(int x, int y, vector<vector<int>> &m, int n, string &curr, vector<string> &res){
        if(!isValid(x,y,m,n)) return;
        if(x==n-1 && y==n-1){
            res.push_back(curr);
            return;
        }
        m[x][y]=0;
        for(int i=0;i<4;i++){
            curr+=dir[i];
            dfs(x+del[i],y+del[i+1],m,n,curr,res);
            curr.pop_back();
        }
        m[x][y]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string curr="";
        dfs(0,0,m,n,curr,res);
        return res;
    }
};