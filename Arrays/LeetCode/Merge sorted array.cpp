//problem link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //shift nums1 elements to the end of nums1, then use two pointer approach
        int idx=m+n-1;
        for(int i=m-1;i>=0;i--){
            nums1[idx--]=nums1[i];
        }
        idx++;
        int i=0, j=0, k=0;;
        while(i<m && j<n){
            if(nums1[i+idx] <= nums2[j]){
                nums1[k++]=nums1[i+idx];
                i++;
            }
            else nums1[k++]=nums2[j++];
        }
        while(i<m){
            nums1[k++]=nums1[i+idx];
            i++;
        }
        while(j<n){
            nums1[k++]=nums2[j++];
        }
    }
};