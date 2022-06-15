//problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size(), n=arr2.size();
        if(m>n) return findMedianSortedArrays(arr2,arr1);
        int l=0, r=m;
        while(l<=r){
            int i=l+(r-l)/2;
            int j=(m+n+1)/2-i;
            int min1=(i==m)?INT_MAX:arr1[i];
            int max1=(i==0)?INT_MIN:arr1[i-1];
            int min2=(j==n)?INT_MAX:arr2[j];
            int max2=(j==0)?INT_MIN:arr2[j-1];
            if(max2>min1) l=i+1;
            else if(max1>min2) r=i-1;
            else{
                if((m+n)%2==0) return (max(max1,max2)+min(min1,min2))/2.0;
                else return max(max1,max2);
            }
        }
        return -1;
    }
};