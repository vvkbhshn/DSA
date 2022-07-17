//problem link: https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    
    void findCoordinates(int target, int n, int &x, int &y){
        int q=target/n;
        if(target%n==0){            
            x=n-q;
            if(q&1) y=n-1;
            else y=0;
        }
        else{
            x=n-1-q;
            if(q&1) y=n-(target%n);
            else y=(target%n)-1;
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(), numMoves=0;
        queue<int> q;
        q.push(1);
        board[n-1][0]=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int num=q.front(); q.pop();
                if(num==n*n) return numMoves;
                int x,y;
                for(int i=1;i<=6;i++){
                    int target=num+i;
                    if(target>n*n) break;
                    findCoordinates(target,n,x,y); 
                    if(board[x][y]==0) continue;
                    if(board[x][y]!=-1) q.push(board[x][y]);
                    else q.push(target);
                    board[x][y]=0;
                }
            }
            numMoves++;
        }
        return -1;
    }
};