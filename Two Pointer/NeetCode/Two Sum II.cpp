//problem link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        vector<int> res;
        int i=0, j=numbers.size()-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum>target) j--;
            else if(sum<target) i++;
            else{
                res={i+1,j+1};
                break;
            }
        }
        return res;
    }
};