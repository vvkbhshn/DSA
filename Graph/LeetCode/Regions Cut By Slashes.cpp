//problem link: https://leetcode.com/problems/regions-cut-by-slashes/

class Solution {
public:
    vector<int> parent;
    int n,count;
    
    int f(int i, int j, int k){
        return 4*(i*n+j)+k;
    }
    
    int findRegion(int x){
        if(parent[x]!=x) parent[x]=findRegion(parent[x]);
        return parent[x];
    }
    
    void unionRegion(int x, int y){
        x=findRegion(x);
        y=findRegion(y);
        if(x!=y){
            parent[x]=y;
            count--;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        //Method-1: Union find
        //split a cell into four parts, top is 0, right is 1, bottom is 2, left is 3
        n=grid.size();   
        count=n*n*4;
        for(int i=0;i<n*n*4;i++) parent.push_back(i);        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //union current cell's top part with the above cell's bottom part
                if(i>0) unionRegion(f(i,j,0),f(i-1,j,2)); 
                //union current cell's left part with the left cell's right part
                if(j>0) unionRegion(f(i,j,3),f(i,j-1,1));
                
                if(grid[i][j]!='/'){ //grid[i][j] can be ' ' or '\'                    
                    unionRegion(f(i,j,0),f(i,j,1)); //union of top and right part
                    unionRegion(f(i,j,2),f(i,j,3)); //union of bottom and left part                
                }
                if(grid[i][j]!='\\'){ //ggrid[i][j] can be ' ' or '/' 
                    unionRegion(f(i,j,0),f(i,j,3)); //union of top and left part
                    unionRegion(f(i,j,2),f(i,j,1)); //union of bottom and right part
                }
            }
        }
        return count;
        
        //Method-2: DFS (https://leetcode.com/problems/regions-cut-by-slashes/discuss/205674/DFS-on-upscaled-grid)
    }
};