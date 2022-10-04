//problem link: https://www.interviewbit.com/problems/self-permutation/

int Solution::permuteStrings(string A, string B) {
    if(A.length()!=B.length()) return 0;
    int freq[26]={0};
    for(int i=0;i<A.length();i++){
        freq[A[i]-'a']++;
        freq[B[i]-'a']--;
    }
    for(int i=0;i<26;i++) if(freq[i]!=0) return 0;
    return 1;
}
