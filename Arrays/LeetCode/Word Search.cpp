//problem link: https://leetcode.com/problems/word-search/

class Solution {
public:    
    bool backtrack(vector<vector<char>> &board, string &word, int idx, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='#') return false;
        if(word[idx]!=board[i][j]) return false;
        if(idx==word.length()-1) return true;
        char temp=board[i][j];
        //to prevent using a separate visited array
        board[i][j]='#';
        bool res=backtrack(board,word,idx+1,i+1,j)||backtrack(board,word,idx+1,i-1,j)||
                 backtrack(board,word,idx+1,i,j+1)||backtrack(board,word,idx+1,i,j-1);
        board[i][j]=temp;
        return res;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtrack(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};