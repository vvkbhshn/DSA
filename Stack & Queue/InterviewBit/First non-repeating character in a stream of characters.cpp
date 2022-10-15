//problem link: https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/hints/

string Solution::solve(string A) {
    string res;
    int freq[26]={0};
    queue<char> q;
    for(auto c:A){
        freq[c-'a']++;
        if(freq[c-'a']==1) q.push(c);
        while(!q.empty() && freq[q.front()-'a']>1) q.pop();
        if(!q.empty()) res+=q.front();
        else res+='#';
    }
    return res;
}
