//problem link: https://www.interviewbit.com/problems/word-ladder-i/

int Solution::solve(string A, string B, vector<string> &C) {
    if(A.length()!=B.length()) return 0;
    int n=A.length();
    unordered_set<string> mp;
    for(auto &s:C) if(s.length()==n) mp.insert(s);
    int steps=1;
    queue<string> q;
    q.push(A);
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            string s=q.front();
            q.pop();
            if(s.length()!=n) continue;
            if(s==B) return steps;
            for(int i=0;i<n;i++){
                char copy=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(mp.find(s)!=mp.end()){
                        q.push(s);
                        mp.erase(s);
                    }
                }
                s[i]=copy;
            }
        }
        steps++;
    }
    return 0;
}
