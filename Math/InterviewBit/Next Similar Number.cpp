//problem link: https://www.interviewbit.com/problems/next-similar-number/

string Solution::solve(string A) {
    //find Next Permutation
    int n=A.length();
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1) return "-1";
    for(int i=n-1;i>idx;i--){
        if(A[i]>A[idx]){
            swap(A[i],A[idx]);
            break;
        }
    }
    reverse(A.begin()+idx+1,A.end());
    return A;
}
