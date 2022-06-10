//problem link: https://www.interviewbit.com/problems/search-for-a-range/

vector<int> search(const vector<int> &A, int target, int l, int r){
    if(A[l]==target && A[r]==target) return {l,r};
    if(target>=A[l] && target<=A[r]){
        int mid=l+(r-l)/2;
        vector<int> left=search(A,target,l,mid);
        vector<int> right=search(A,target,mid+1,r);
        if(left[0]!=-1 && right[0]!=-1) return {left[0],right[1]};
        return left[0]==-1 ? right: left;
    }
    return {-1,-1};
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Divide and Conquer
    int n=A.size();
    return search(A,B,0,n-1);
}
