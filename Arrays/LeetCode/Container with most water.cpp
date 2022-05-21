//problem link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //Assume that height[left] <= height[right] now and we left shift the right pointer. 
        // It will comes two following situations:
        //1.height[new_right] >= height[original_right]. Obviously, the height of the container is still height[left], but the width is smaller.
        //2.height[new_right] < height[original_right]. In this case, the width of the container is smaller and the height is min(height[left],height[new_right]) <= height[left]=original height.
        //The both situations cannot lead to a lager area. So we just need to right shift the left pointer.
        
        int n=height.size();
        int i=0, j=n-1;
        int res=0;
        while(i<j){
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return res;
    }
};