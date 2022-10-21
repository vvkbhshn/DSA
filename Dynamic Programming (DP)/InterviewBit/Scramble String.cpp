//problem link: https://www.interviewbit.com/problems/scramble-string/

bool check(const string A, const string B, unordered_map<string,bool> &dp){    
    int n=A.length();  
    if(A==B) return true;
    if(n==1) return false;
    
    string key=A+" "+B;
    if(dp.find(key)!=dp.end()) return dp[key];    
    
    int freq[26]={0};
    for(int i=0;i<n;i++){
        freq[A[i]-'a']++;
        freq[B[i]-'a']--;
    }
    for(int i=0;i<26;i++) if(freq[i]!=0) return dp[key]=false;

    for(int i=1;i<n;i++){
        bool withoutSwap = check(A.substr(0,i),B.substr(0,i),dp) && check(A.substr(i),B.substr(i),dp);
        if(withoutSwap) return dp[key]=true;
        bool withSwap = check(A.substr(0,i),B.substr(n-i),dp) && check(A.substr(i),B.substr(0,n-i),dp);
        if(withSwap) return dp[key]=true;
    }
    return dp[key]=false;
}

int Solution::isScramble(const string A, const string B) {
    if(A.length()!=B.length()) return 0;
    unordered_map<string,bool> dp;
    string s=A, t=B;
    return check(s,t,dp);
}