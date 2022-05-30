bool isValid(bool graph[101][101], vector<int> &color, int n, int node, int curr){
    for(int i=0;i<n;i++) if(i!=node && graph[node][i]==1 && color[i]==curr) return false;
    return true;
}


bool doColoring(bool graph[101][101], vector<int> &color, int m, int n, int node){
    if(node==n) return true;
    for(int i=1;i<=m;i++){
        if(isValid(graph,color,n,node,i)){
            color[node]=i;
            if(doColoring(graph,color,m,n,node+1)) return true;
            color[node]=0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> color(n,0);
    return doColoring(graph,color,m,n,0);
}