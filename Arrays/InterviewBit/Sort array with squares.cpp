//problem link: https://www.interviewbit.com/problems/sort-array-with-squares/

vector<int> Solution::solve(vector<int> &A) {
    int n=A.size(), k=n-1;
    int i=0, j=n-1;
    vector<int> res(n);
    while(i<=j){
        if(abs(A[i])>abs(A[j])){
            res[k--]=A[i]*A[i];
            i++;
        }
        else{
            res[k--]=A[j]*A[j];
            j--;
        }
    }
    return res;
}
