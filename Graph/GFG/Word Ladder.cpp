//problem link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.length();
        unordered_set<string> mp(wordList.begin(),wordList.end());
        if(mp.find(endWord)==mp.end()) return 0;
        int words=1;
        queue<string> q;
        q.push(beginWord);  
        mp.erase(beginWord);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string s=q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    char temp=s[i];
                    for(char c='a';c<='z';c++){
                        s[i]=c;
                        if(s==endWord) return words+1;
                        if(mp.find(s)!=mp.end()){
                            q.push(s);
                            mp.erase(s);
                        }
                    }
                    s[i]=temp;
                }
            }
            words++;
        }
        return 0;   
    }
};