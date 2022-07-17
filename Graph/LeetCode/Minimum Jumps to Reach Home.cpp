//problem link: https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> s(forbidden.begin(),forbidden.end());
        int jump=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto p=q.front();
                q.pop();
                int pos=p.first, back=p.second;
                if(pos==x) return jump;
                if(s.find(pos)!=s.end()) continue;
                s.insert(pos);
                if(back==0 && pos>=b) q.push({pos-b,1});
                if(pos<=(2000+b)) q.push({pos+a,0});                
            }
            jump++;
        }
        return -1;
    }
};