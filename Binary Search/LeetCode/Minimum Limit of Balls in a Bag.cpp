//problem link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    int minimumSize(vector<int>& arr, int maxOperations) {
        int n=arr.size();
        int l=1,r=*max_element(arr.begin(),arr.end()),mid;
        while(l<r){
            mid=l+(r-l)/2;
            int cnt=0;
            for(int x:arr){
                if(x%mid==0) cnt+=(x/mid)-1;
                else cnt+=x/mid;
            }
            if(cnt>maxOperations) l=mid+1;
            else r=mid;
        }
        return l;
    }
};