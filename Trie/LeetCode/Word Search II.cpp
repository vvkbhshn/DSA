//problem link: https://leetcode.com/problems/word-search-ii/

class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;    
    TrieNode(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isEnd=false;
    }    
};

class Solution {
public:    
    void solve(int x, int y, int m, int n, TrieNode* root, string &temp, vector<vector<char>>& board, vector<string> &res){
        if(x<0 || y<0 || x>=m || y>=n || board[x][y]=='.') return;        
        char c=board[x][y];        
        if(root->child[c-'a']==NULL) return;        
        temp.push_back(c);
        root=root->child[c-'a'];
        if(root->isEnd){
            res.push_back(temp);
            root->isEnd=false;
        }
        board[x][y]='.';        
        solve(x+1,y,m,n,root,temp,board,res);
        solve(x-1,y,m,n,root,temp,board,res);
        solve(x,y+1,m,n,root,temp,board,res);
        solve(x,y-1,m,n,root,temp,board,res);        
        board[x][y]=c;
        temp.pop_back();
    }   
    
    void insert(TrieNode* root, string &word){
        TrieNode* curr=root;
        for(auto c:word){
            int index=c-'a';
            if(curr->child[index]==NULL) curr->child[index]=new TrieNode();
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(), n=board[0].size();
        vector<string> res;
        TrieNode *root=new TrieNode();
        for(auto &s:words){
            insert(root,s);
        }
        string temp;        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){                
                solve(i,j,m,n,root,temp,board,res);
            }
        }
        return res;
    }
};