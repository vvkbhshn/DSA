//problem link: https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int m=A.size(), n=B.size();
    vector<int> res;
    int i=0, j=0;
    while(i<m && j<n){
        if(A[i]<B[j]) i++;
        else if(A[i]>B[j]) j++;
        else{
            res.push_back(A[i]);
            i++;
            j++;
        }
    }
    return res;
}
