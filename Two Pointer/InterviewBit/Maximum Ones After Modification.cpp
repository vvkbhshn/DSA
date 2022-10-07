//problem link: https://www.interviewbit.com/problems/maximum-ones-after-modification/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size(), cnt=0, res=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(A[j]==0){
            cnt++;
            if(cnt>B){
                while(i<n && A[i]==1) i++;
                i++;
                cnt--;
            }
        }
        res=max(res,j-i+1);
        j++;
    }
    return res;
}
