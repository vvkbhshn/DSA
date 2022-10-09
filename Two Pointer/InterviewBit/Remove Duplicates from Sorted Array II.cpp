//problem link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    int n=A.size();
    int i=0, j=1, cnt=1;
    while(j<n){
        if(A[j]!=A[i]){
            A[++i]=A[j];
            cnt=1;
        }
        else if(cnt==1){
            A[++i]=A[j];
            cnt=2;
        }
        j++;
    }
    return i+1;
}
