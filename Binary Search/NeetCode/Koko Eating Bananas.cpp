//problem link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo=1, hi=*max_element(piles.begin(), piles.end()), res=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long cnt=0;
            for(auto x:piles){
                cnt+=(x+mid-1)/mid;
            }
            if(cnt>h) lo=mid+1;
            else{
                res=mid;
                hi=mid-1;                
            }
        }
        return res;
    }
};