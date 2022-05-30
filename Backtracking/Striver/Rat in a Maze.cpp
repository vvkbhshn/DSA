//problem link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

void findPath(vector<vector<int>> &m, vector<string> &res, string &temp, int n, int x, int y){
    if(x<0 || y<0 || x>=n || y>=n || m[x][y]==0) return;
    if(x==n-1 && y==n-1){
        res.push_back(temp);
        return;
    }
    m[x][y]=0;
    temp+='D';
    findPath(m,res,temp,n,x+1,y);
    temp.pop_back();
    temp+='L';
    findPath(m,res,temp,n,x,y-1);
    temp.pop_back();
    temp+='R';
    findPath(m,res,temp,n,x,y+1);
    temp.pop_back();
    temp+='U';
    findPath(m,res,temp,n,x-1,y);
    temp.pop_back();
    m[x][y]=1;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> res;
    string temp;
    findPath(m,res,temp,n,0,0);
    return res;
}