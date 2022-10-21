//problem link: https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

int dfs(int curr, int parent, vector<int> adj[], int &maxLength){
    if(adj[curr].size()==1 && adj[curr][0]==parent) return 0;
    int res=0;
    int maxBranchLength=0, secondMaxBranchLength=0;
    for(auto next:adj[curr]){
        if(next!=parent){
            int pathLength=1+dfs(next,curr,adj,maxLength);
            if(pathLength>maxBranchLength){
                secondMaxBranchLength=maxBranchLength;
                maxBranchLength=pathLength;
            }
            else if(pathLength>secondMaxBranchLength){
                secondMaxBranchLength=pathLength;
            }
        }
    }
    maxLength=max(maxLength,maxBranchLength+secondMaxBranchLength);
    return maxBranchLength;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n==1) return 0;
    int root;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        if(A[i]==-1) root=i;
        else{
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    int maxLength=0;
    dfs(root,-1,adj,maxLength);    
    return maxLength;
}