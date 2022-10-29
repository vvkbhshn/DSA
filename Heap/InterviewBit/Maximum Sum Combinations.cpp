//problem link: https://www.interviewbit.com/problems/maximum-sum-combinations/

struct Item{
    int sum,x,y;
    Item(int a, int b, int c){
        sum=a; x=b; y=c;
    }    
};
struct myCmp{
    bool operator()(Item &a, Item &b){
        return a.sum<b.sum;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> res;
    int n=A.size();
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    priority_queue<Item,vector<Item>,myCmp> pq;
    set<pair<int,int>> vis;
    pq.push(Item(A[0]+B[0],0,0));    
    while(C--){
        Item curr=pq.top();
        pq.pop();
        res.push_back(curr.sum);
        int i=curr.x, j=curr.y;
        if(vis.find({i+1,j})==vis.end()){
            pq.push(Item(A[i+1]+B[j],i+1,j));
            vis.insert({i+1,j});
        }
        if(vis.find({i,j+1})==vis.end()){
            pq.push(Item(A[i]+B[j+1],i,j+1));
            vis.insert({i,j+1});
        }
    }      
    return res;
}