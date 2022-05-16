//problem link: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    //BFS solution
    // bool vis[10009];    
    // int bfs(vector<int>&nums, bool vis[]){
    //     int res=0, n=nums.size();
    //     vis[0]=true;
    //     queue<int> q;
    //     q.push(0);
    //     vis[0]=true;
    //     int curr_level=1, next_level=0;
    //     while(!q.empty()){
    //         int node=q.front();
    //         q.pop();
    //         if(node==n-1) break;
    //         for(int i=1;i<=nums[node];i++){
    //             if(node+i<n && !vis[node+i]){
    //                 q.push(node+i);
    //                 vis[node+i]=true;
    //                 next_level++;
    //             }
    //         }
    //         curr_level--;
    //         if(curr_level==0){
    //             curr_level=next_level;
    //             next_level=0;
    //             res++;
    //         }
    //     }
    //     return res;
    // }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        // BFS O(n) solution
        // memset(vis,false,sizeof(vis));
        // return bfs(nums,vis);
        
        //Greedy O(n) solution
        int res=0, currMax=0, totalMax=0;
        for(int i=0;i<n;i++){
            if(totalMax>=n-1) break;
            currMax=max(currMax,i+nums[i]);
            if(i==totalMax){
                res++;
                totalMax=currMax;
            }            
        }
        return res;
    }
};