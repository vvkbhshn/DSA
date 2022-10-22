//problem link: https://www.interviewbit.com/problems/min-cost-path/

struct cell{
    int val, x, y;
    cell(int a, int b, int c) {val=a; x=b; y=c;}
};

struct myCmp{
    bool operator()(const cell &a, const cell &b){
        return a.val>b.val;
    }
};

int Solution::solve(int A, int B, vector<string> &C) {
    //Dijkstra's algorithm
    vector<vector<int>> dist(A,vector<int>(B,INT_MAX));
    int dir[5]={1,0,-1,0,1}; // D,L,U,R
    unordered_map<char,int> mp={{'D',0},{'L',1},{'U',2},{'R',3}};    
    priority_queue<cell,vector<cell>,myCmp> pq;
    pq.push(cell(0,0,0));
    dist[0][0]=0;
    while(!pq.empty()){
        cell curr=pq.top();
        pq.pop();
        int currX=curr.x, currY=curr.y;
        if(currX==A-1 && currY==B-1) break;
        for(int k=0;k<4;k++){
            int nextX=currX+dir[k], nextY=currY+dir[k+1];
            if(nextX<0 || nextX>=A || nextY<0 || nextY>=B) continue;
            char c=C[currX][currY];
            if(k==mp[c] && dist[currX][currY]<dist[nextX][nextY]){
                dist[nextX][nextY]=dist[currX][currY];
                pq.push(cell(dist[nextX][nextY],nextX,nextY));
            }
            else if(k!=mp[c] && 1+dist[currX][currY]<dist[nextX][nextY]){
                dist[nextX][nextY]=1+dist[currX][currY];
                pq.push(cell(dist[nextX][nextY],nextX,nextY));
            }
        }
    }
    if(dist[A-1][B-1]==INT_MAX) -1;
    return dist[A-1][B-1];
}