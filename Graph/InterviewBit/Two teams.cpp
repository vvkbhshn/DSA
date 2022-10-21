//problem link: https://www.interviewbit.com/problems/two-teams/

bool isPossible(int u, vector<int> adj[], vector<int> &color, int currColor){
    bool res=true;
    if(color[u]==-1) color[u]=currColor;
    for(auto v:adj[u]){
        if(color[v]>=0 && color[u]==color[v]) return false;
        else if(color[v]==-1 && !isPossible(v,adj,color,1-currColor)) return false;
    }
    return true;
}

int Solution::solve(int A, vector<vector<int>> &B) {
    vector<int> color(A+1,-1);
    vector<int> adj[A+1];
    for(auto &v:B){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    for(int i=1;i<=A;i++){
        if(color[i]==-1 && !isPossible(i,adj,color,1)) return 0;
    }
    return 1;
}