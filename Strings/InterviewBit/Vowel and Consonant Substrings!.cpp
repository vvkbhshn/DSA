//problem link: https://www.interviewbit.com/problems/vowel-and-consonant-substrings/

bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int Solution::solve(string A) {
    int n=A.length(), MOD=1e9+7;
    long long res=0;
    int vowel=0, cons=0;
    for(int i=0;i<n;i++){
        if(isVowel(A[i])){
            vowel++;
            res=(res+cons)%MOD;
        }
        else{
            cons++;
            res=(res+vowel)%MOD;
        }
    }
    return res;
}
