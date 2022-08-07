//problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    bool isValid(vector<vector<int>> &m, int n, int i, int j){
        return min(i,j)>=0 && max(i,j)<n && m[i][j]==1;
    }
    
    void traverseMaze(vector<vector<int>> &m, int n, vector<string> &res, string &temp, int i, int j){
        if(!isValid(m,n,i,j)) return;
        if(i==n-1 && j==n-1){
            res.push_back(temp);
            return;
        }
        m[i][j]=0;
        
        temp+='U';
        traverseMaze(m,n,res,temp,i-1,j);
        temp.pop_back();
        
        temp+='D';
        traverseMaze(m,n,res,temp,i+1,j);
        temp.pop_back();
        
        temp+='L';
        traverseMaze(m,n,res,temp,i,j-1);
        temp.pop_back();
        
        temp+='R';
        traverseMaze(m,n,res,temp,i,j+1);
        temp.pop_back();
        
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string temp="";
        traverseMaze(m,n,res,temp,0,0);
        return res;
    }
};