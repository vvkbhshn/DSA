//problem link: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<n;i++){
            int a=nums[i];
            int l=i+1, r=n-1;
            while(l<r){
                int b=nums[l]+nums[r];
                if(b==target-a){
                    res=target;
                    break;
                }
                else if(b<target-a){
                    if(abs(target-(a+b))<abs(target-res)) res=a+b;
                    l++;
                }
                else{
                    if(abs(target-(a+b))<abs(target-res)) res=a+b;
                    r--;
                }
            }
        }
        return res;
    }
};