//problem link: https://www.interviewbit.com/problems/string-and-its-frequency/

string Solution::solve(string A) {
    int n=A.length();
    int freq[26]={0};
    for(auto c:A) freq[c-'a']++;
    string res;
    for(auto c:A){
        if(freq[c-'a']>0){
            res+=c+to_string(freq[c-'a']);
            freq[c-'a']=0;
        }
    }
    return res;
}
