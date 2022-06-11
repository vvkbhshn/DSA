// problem link: https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m=A.size(), n=B.size();
    if(m>n) return findMedianSortedArrays(B,A);
    int l=0, r=m;
    while(l<=r){
        int i=l+(r-l)/2;
        int j=(m+n+1)/2-i;
        int min1=(i==m)?INT_MAX:A[i];
        int max1=(i==0)?INT_MIN:A[i-1];
        int min2=(j==n)?INT_MAX:B[j];
        int max2=(j==0)?INT_MIN:B[j-1];
        if(max1>min2)  r=i-1;
        else if(max2>min1) l=i+1;
        else{
            if((m+n)%2==0) return (max(max1,max2)+min(min1,min2))/2.0;
            else return max(max1,max2);
        }
    }
}
