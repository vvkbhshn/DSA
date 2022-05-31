//problem link: https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Method-1:
        int pos1=INT_MIN, pos2=INT_MIN, pos3=INT_MIN;
        int neg1=INT_MAX, neg2=INT_MAX, neg3=INT_MAX;
        for(auto x:nums){
            if(x>=pos1){
                pos3=pos2;
                pos2=pos1;
                pos1=x;
            }
            else if(x>=pos2){
                pos3=pos2;
                pos2=x;
            }
            else if(x>=pos3){
                pos3=x;
            }
            
            if(x<=neg1){
                neg2=neg1;
                neg1=x;
            }
            else if(x<=neg2){
                neg2=x;
            }
        }
        return max(neg1*neg2*pos1, pos1*pos2*pos3);
        
        // Method-2 (sorting)
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};