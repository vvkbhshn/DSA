//problem link: https://leetcode.com/problems/game-of-life/

class Solution {
public:
    int check(vector<vector<int>> &board, int i, int j, int &m, int &n){
        int res=0;
        if(i-1>=0){
            if(j-1>=0 && board[i-1][j-1]>0) res++;
            if(board[i-1][j]>0) res++;
            if(j+1<n && board[i-1][j+1]>0) res++;
        }
        if(j-1>=0 && board[i][j-1]>0) res++;
        if(j+1<n && board[i][j+1]>0) res++;
        if(i+1<m){
            if(j-1>=0 && board[i+1][j-1]>0) res++;
            if(board[i+1][j]>0) res++;
            if(j+1<n && board[i+1][j+1]>0) res++;
        }
        return res;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=check(board,i,j,m,n);
                if(board[i][j]==1 && (temp<2 || temp>3)) board[i][j]=2;
                else if(board[i][j]==0 && temp==3) board[i][j]=-1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //dead -> dead = 0
                //dead -> live = -1
                //live -> dead = 2
                //live -> live = 1
                if(board[i][j]==1 || board[i][j]==-1) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};