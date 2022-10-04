//problem link: https://www.interviewbit.com/problems/amazing-subarrays/

bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int Solution::solve(string A) {
    int MOD=10003, res=0;
    int n=A.length();
    for(int i=0;i<n;i++){
        if(isVowel(tolower(A[i]))) res=(res+n-i)%MOD;
    }
    return res;
}
