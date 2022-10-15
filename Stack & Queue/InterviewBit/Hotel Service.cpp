//problem link: https://www.interviewbit.com/problems/hotel-service/

bool isValid(int n, int m, int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n=A.size(), m=A[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<array<int,3>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1){
				dist[i][j]=0;
            	q.push({0,i,j});
			}
        }
    }
    int dir[5]={1,0,-1,0,1};
    while(!q.empty()){
        auto v=q.front();
        q.pop();
        int x=v[1], y=v[2], distance=v[0];
        for(int i=0;i<4;i++){
            int X=x+dir[i], Y=y+dir[i+1];
            if(isValid(n,m,X,Y) && dist[X][Y]==-1){
                dist[X][Y]=1+dist[x][y];
                q.push({dist[X][Y],X,Y});
            }
        }
    }
    vector<int> res;
    for(auto v:B) res.push_back(dist[v[0]-1][v[1]-1]);
	return res;
}