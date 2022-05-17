//problem link: https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r, int &cnt){
        int n1=mid-l+1, n2=r-mid;
        // count no. of reverse pairs
        int i, j=mid+1;
        for(i=l;i<=mid;i++){
            while(j<=r && (long)nums[i]>2*(long)nums[j]) j++;
            cnt+=j-(mid+1);
        }   
        // merge left and right array
        int a[n1], b[n2];
        for(int i=0;i<n1;i++) a[i]=nums[l+i];
        for(int i=0;i<n2;i++) b[i]=nums[mid+1+i];
        i=0, j=0;
        int k=l;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]) nums[k++]=a[i++];
            else nums[k++]=b[j++];
        }
        while(i<n1) nums[k++]=a[i++];
        while(j<n2) nums[k++]=b[j++];
    }
    
    void mergeSort(vector<int> &nums, int l, int r, int &cnt){
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(nums,l,mid,cnt);
            mergeSort(nums,mid+1,r,cnt);
            merge(nums,l,mid,r,cnt);
        }
    }
    
    
    int reversePairs(vector<int>& nums) {
        //Merge Sort solution: O(nlogn) time
        int cnt=0;
        mergeSort(nums,0,nums.size()-1,cnt);
        return cnt;
    }
};