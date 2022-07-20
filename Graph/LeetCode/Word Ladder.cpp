//problem link: https://leetcode.com/problems/word-ladder/

class Solution {
public:    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.length()!=endWord.length()) return 0;
        unordered_set<string> words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()) return 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int changes=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                if(curr==endWord) return changes;
                q.pop();
                for(int i=0;i<curr.length();i++){
                    char temp=curr[i];
                    //make every possible word that differs by a single letter
                    for(char c='a';c<='z';c++){
                        curr[i]=c;
                        if(words.find(curr)!=words.end() &&
                           vis.find(curr)==vis.end()){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                    curr[i]=temp;
                }
            }
            changes++;
        }
        return 0;
    }
};