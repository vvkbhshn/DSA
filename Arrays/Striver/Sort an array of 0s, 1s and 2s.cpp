//problem link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0, id0=0, id2=n-1;
        while(i<=id2){
            if(nums[i]==0){
                swap(nums[i],nums[id0]);
                i++;
                id0++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[id2]);
                id2--;
            }
            else i++;
        }
        
        //Method 2: requires 2 traversal :(
        // int n0=0,n1=0,n2=0;
        // for(auto x:nums){
        //     if(x==0) n0++;
        //     else if(x==1) n1++;
        //     else n2++;
        // }
        // for(int i=0;i<n0;i++) nums[i]=0;
        // for(int i=n0;i<n0+n1;i++) nums[i]=1;
        // for(int i=n0+n1;i<n;i++) nums[i]=2;
    }
};