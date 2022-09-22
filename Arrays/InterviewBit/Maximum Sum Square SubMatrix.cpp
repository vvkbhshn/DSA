//problem link: https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++) A[i][j]+=A[i][j-1];
    }    
    for(int k=B-1;k<n;k++){
        int i=0, j=0, subarraySum=0;
        while(j<n){
            subarraySum+=A[j][k];
            if(k>=B) subarraySum-=A[j][k-B];
            if(j-i+1<B) j++;
            else if(j-i+1==B){
                j++;
                res=max(res,subarraySum);
            }
            else{
                subarraySum-=A[i][k];
                if(k>=B) subarraySum+=A[i][k-B];
                i++;
                j++;
                res=max(res,subarraySum);
            }
        }
    }
    return res;
}
