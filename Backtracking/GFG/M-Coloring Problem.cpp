//problem link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:
    bool isValid(bool graph[][101], vector<int> &color, int n, int node, int nodeColor){
        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && color[i]==nodeColor) return false;
        }
        return true;
    }

    bool backtrack(bool graph[][101], vector<int> &color, int m, int n){
        for(int i=0;i<n;i++){
            if(color[i]==0){
                for(int j=1;j<=m;j++){
                    if(isValid(graph,color,n,i,j)){
                        color[i]=j;
                        if(backtrack(graph,color,m,n)) return true;
                        color[i]=0;
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return backtrack(graph,color,m,n);
    }
};