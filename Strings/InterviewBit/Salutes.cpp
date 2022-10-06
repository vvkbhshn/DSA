//problem link: https://www.interviewbit.com/problems/salutes/

long Solution::countSalutes(string A) {
    int n=A.length();
    long res=0, cnt=0;
    for(int i=n-1;i>=0;i--){
        if(A[i]=='<') cnt++;
        else res+=cnt;
    }
    return res;
}
