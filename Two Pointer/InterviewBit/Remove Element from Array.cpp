//problem link: https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &A, int B) {
    int n=A.size();
    int i=0, j=0;
    while(j<n){
        if(A[j]!=B){
            A[i++]=A[j];
        }
        j++;
    }
    return i;
}
