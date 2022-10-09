//problem link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    int i=0, j=1;
    while(j<A.size()){
        if(A[j]!=A[i]){
            A[++i]=A[j];
        }
        j++;
    }
    return i+1;
}
