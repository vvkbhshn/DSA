//problem link: https://www.interviewbit.com/problems/word-ladder-ii/

void dfs(vector<string> &curr, string &end, unordered_set<string> &wordDict, vector<vector<string>> &res, int &minDist){    
    int n=curr.size();
    if(n>minDist) return;
    else if(n==minDist && curr.back()==end){
        res.push_back(curr);
        return;
    } 
    string currWord=curr.back();
    for(int i=0;i<currWord.length();i++){
        char copy=currWord[i];
        for(char c='a';c<='z';c++){
            currWord[i]=c;
            if(wordDict.find(currWord)!=wordDict.end()){
                wordDict.erase(currWord);
                curr.push_back(currWord);
                dfs(curr,end,wordDict,res,minDist);
                curr.pop_back();
                wordDict.insert(currWord);
            }
        }
        currWord[i]=copy;
    }    
}

int findMinDist(string start, string end, unordered_set<string> wordDict){    
    int steps=0;
    queue<string> q;
    q.push(start);
	wordDict.erase(start);
    while(!q.empty()){
        int n=q.size();
        bool found=false;
        while(n--){
            string s=q.front();
            q.pop();
            if(s==end){
                found=true;
                break;
            }
            for(int i=0;i<s.length();i++){
                char copy=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(wordDict.find(s)!=wordDict.end()){
                        q.push(s);
                        wordDict.erase(s);
                    }
                }
                s[i]=copy;
            }
        }
        if(found) return steps+1;
        steps++;
    }
    return steps;
}

vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dict) {
    vector<vector<string>> res;
    unordered_set<string> wordDict(dict.begin(),dict.end());
    wordDict.insert(end);
    int minDist=findMinDist(start,end,wordDict);
    if(minDist==1 && start!=end) return res;
    vector<string> curr;
    wordDict.erase(start);
    curr.push_back(start);
    dfs(curr,end,wordDict,res,minDist);
    return res;
}