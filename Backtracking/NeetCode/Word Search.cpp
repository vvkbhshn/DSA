//problem link: https://leetcode.com/problems/word-search/

class Solution {   
public:
    bool isValid(int x, int y, vector<vector<char>>& board){
        return x>=0 && x<board.size() && y>=0 && y<board[0].size();
    }
    
    bool findWord(vector<vector<char>>& board, string &word, int index, int x, int y){  
        if(!isValid(x,y,board) || board[x][y]!=word[index]) return false;
        if(index==word.length()-1) return true;
        board[x][y]='.';
        if(findWord(board,word,index+1,x+1,y) || findWord(board,word,index+1,x-1,y) || findWord(board,word,index+1,x,y-1) || findWord(board,word,index+1,x,y+1)) return true;
        board[x][y]=word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(findWord(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};