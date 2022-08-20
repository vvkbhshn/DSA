//problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int n=heights.size(), res=0;
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                int h=heights[s.top()];
                s.pop();
                int w=i;
                if(!s.empty()) w=i-s.top()-1;
                res=max(res,h*w);
            }
            s.push(i);
        }
        heights.pop_back();
        return res;
    }
};