//problem link: https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    int res=0;
    int i=A.length()-1;
    while(i>=0 && A[i]==' '){
        i--;
    }
    while(i>=0 && A[i]!=' '){
        res++;
        i--;
    }
    return res;
}
