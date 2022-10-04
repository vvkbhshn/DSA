//problem link: https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    string s="1";
    if(A==1) return s;
    for(int i=0;i<A-1;i++){
        string t;
        char c=s[0];
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) cnt++;
            else if(s[i]!=s[i-1]){
                t+=to_string(cnt)+c;
                c=s[i];
                cnt=1;
            }
        }
        t+=to_string(cnt)+c;
        s=t;
    }
    return s;
}
