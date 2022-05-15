//problem link: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algorithm
        int n=nums.size();
        int cnt=1, temp=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==temp) cnt++;
            else{
                cnt--;
                if(cnt==0){
                    temp=nums[i];
                    cnt=1;
                }
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==temp) cnt++;
        }
        if(cnt>n/2) return temp;
        return -1;
    }
};