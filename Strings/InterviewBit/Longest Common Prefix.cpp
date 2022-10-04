//problem link: https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    int n=A.size();
    int len=INT_MAX;
    string res;
    for(auto &s:A) len=min<int>(len,s.length());
    for(int i=0;i<len;i++){
        char c=A[0][i];
        int cnt=0;
        for(auto &s:A) if(s[i]==c) cnt++;
        if(cnt==n) res+=c;
        else break;
    }
    return res;
}
