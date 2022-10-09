//problem link: https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    int n=A.size();
    int i=0, j=1;
    while(i<n && j<n){
        int diff=A[j]-A[i];
        if(diff<B) j++;
        else if(diff>B) i++;
        else if(diff==B){
            if(i==j) j++;
            else return 1;
        }
    }
    return 0;
}