//problem link: https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    // Method-1: [Two Pointer] - O(n) time, O(1) space    
    int n=A.size();
    int res=0, sum=0;
    int i=0,j=0;
    while(i<n && j<n){
        sum+=A[j];
        while(sum>=B){
            sum-=A[i];
            i++;
        }
        res+=j-i+1;
        j++;
    }
    return res;
    
    // Method-2: [Binary Search] - O(nlogn) time, O(n) space
    // int n=A.size();
    // vector<int> prefSum(n);
    // prefSum[0]=A[0];
    // for(int i=1;i<n;i++) prefSum[i]=A[i]+prefSum[i-1];
    // int res=0, prev=0;
    // for(int i=0;i<n;i++){
    //     if(i>0) prev=prefSum[i-1];
    //     int lo=i, hi=n-1, j=-1;
    //     while(lo<=hi){
    //         int mid=lo+(hi-lo)/2;
    //         int curr=prefSum[mid]-prev;
    //         if(curr<B){
    //             j=mid;
    //             lo=mid+1;
    //         }
    //         else hi=mid-1;
    //     }
    //     if(j>=i) res+=(j-i+1);
    // }
    // return res;
}