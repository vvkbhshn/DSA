//problem link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord)==dict.end()) return 0;
        int words=1;
        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string curr=q.front();
                q.pop();
                if(curr==endWord) return words;
                for(int i=0;i<curr.length();i++){
                    char copy=curr[i];
                    for(char c='a';c<='z';c++){
                        curr[i]=c;
                        if(dict.find(curr)!=dict.end()){
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                    curr[i]=copy;
                }
            }
            words++;
        }
        return 0;
    }
};