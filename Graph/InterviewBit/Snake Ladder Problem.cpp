//problem link: https://www.interviewbit.com/problems/snake-ladder-problem/

int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int> > &B) {
    unordered_map<int,int> mp;
    for(auto &v:A) mp[v[0]]=v[1];
    for(auto &v:B) mp[v[0]]=v[1];    
    vector<bool> vis(101,false);
    queue<int> q;
    q.push(1);
    vis[1]=true;
    int moves=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int curr=q.front();
            q.pop();
            if(curr==100) return moves;
            for(int i=1;i<=6;i++){
                int next=curr+i;
				if(next>100) break;
                if(!vis[next]){
                    vis[next]=true;
                    if(mp.find(next)!=mp.end()){
                        int x=mp[next];
                        if(!vis[x]){
                            q.push(x);
                            vis[x]=true;
                        }
                    }
                    else q.push(next);
                }
            }
        }       
        moves++;
    }
    return -1;
}