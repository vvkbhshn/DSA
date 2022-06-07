//problem link: https://www.interviewbit.com/problems/next-smallest-palindrome/

string Solution::solve(string A) {
    int n=A.length();
    string B=A;
    for(int i=0;i<=(n-1)/2; i++) B[n-1-i]=B[i];
    if(B>A) return B;
    int i=(n-1)/2;
    while(B[i]=='9'){
        B[i]=B[n-1-i]='0';
        i--;
    }
    if(i>=0){
        B[i]++;
        B[n-1-i]=B[i];
    }
    else{
        B.push_back('1');
        B[0]='1';
    }
    return B;
}
