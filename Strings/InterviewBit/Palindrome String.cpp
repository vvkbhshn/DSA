//problem link: https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    int n=A.length();
    int i=0, j=n-1;
    while(i<j){
        while(i<j && !isalnum(A[i])) i++;
        while(i<j && !isalnum(A[j])) j--;
        if(tolower(A[i])!=tolower(A[j])) return 0;
        i++;
        j--;
    }
    return 1;
}
