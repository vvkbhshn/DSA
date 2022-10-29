//problem link: https://www.interviewbit.com/problems/check-palindrome/

int Solution::solve(string A) {
    int n=A.length();
    int freq[26]={0};
    for(auto c:A) freq[c-'a']++;
    int odd=0;
    for(int i=0;i<26;i++){
        if(freq[i]%2==1) odd++;
        if(odd>1) return 0;
    }
    return 1; 
}