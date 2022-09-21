//problem link: https://www.interviewbit.com/problems/balance-array/

int Solution::solve(vector<int> &A) {
    int n=A.size(), totalEven=0, totalOdd=0;
    for(int i=0;i<n;i++){
        if(i&1) totalOdd=totalOdd+A[i];
        else totalEven+=A[i];
    }
    int res=0;
    int currEven=0, currOdd=0;
    for(int i=0;i<n;i++){
        if(i&1) currOdd+=A[i];
        else currEven+=A[i];
        int remOdd=totalEven-currEven;
        int remEven=totalOdd-currOdd;
        if(i&1 && currEven+remEven==currOdd-A[i]+remOdd) res++;
        else if(i%2==0 && currEven-A[i]+remEven==currOdd+remOdd) res++;      
    }
    return res;
}
