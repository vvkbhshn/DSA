//problem link: https://www.interviewbit.com/problems/step-by-step/

int Solution::solve(int A) {
    A=abs(A);
    int i=0,sum=0;
    while(sum<A || (sum-A)%2==1){
        i++;
        sum+=i;
    }
    return i;
}
