//problem link: https://www.interviewbit.com/problems/minimum-lights-to-activate/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int res=0;
    int i=0;
    while(i<n){
        int j=min(i+B-1,n-1);
        bool lightFound=false;
        while(j>=max(0,i-B+1)){
            if(A[j]==1){
                lightFound=true;
                res++;
                i=j+B;
                break;
            }
            j--;            
        }
        if(!lightFound) return -1;
    }
    return res;
}
