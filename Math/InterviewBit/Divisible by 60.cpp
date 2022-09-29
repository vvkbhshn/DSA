//problem link: https://www.interviewbit.com/problems/divisible-by-60/

int Solution::divisibleBy60(vector<int> &A) {
    int n=A.size();
    if(n==1 && A[0]==0) return 1;
    bool hasZero=false, hasEven=false;
    int sum=0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            if(hasZero && !hasEven) hasEven=true;
            if(!hasZero) hasZero=true;
        }
        else if(A[i]%2==0 && !hasEven) hasEven=true;                 
        sum+=A[i];
    }
    if(sum%3==0 && hasEven && hasZero) return 1;
    return 0;
}

