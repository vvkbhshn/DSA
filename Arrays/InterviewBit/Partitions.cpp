//problem link: https://www.interviewbit.com/problems/partitions/

int Solution::solve(int A, vector<int> &B) {
    int n=B.size();
    int sum=0, res=0;
    for(int i=0;i<n;i++) sum+=B[i];
    if(sum%3!=0) return res;
    int num1=sum/3, num2=2*(sum/3);
    int cnt=0;
    sum=0;
    for(int i=0;i<n-1;i++){
        sum+=B[i];
        if(sum==num2) res+=cnt;
        if(sum==num1) cnt++;
    }
    return res;
}
