//problem link: https://www.interviewbit.com/problems/merge-k-sorted-arrays/

struct Item{
    int val,elemIndex,arrIndex;
    Item(int a,int b,int c){val=a;elemIndex=b;arrIndex=c;}
};

class comp{
    public:
    bool operator()(Item &a, Item& b){
        return a.val>b.val;
    }
};

vector<int> Solution::solve(vector<vector<int>> &A) {
    int k=A.size(), n=A[0].size();
    vector<int> res;
    priority_queue<Item,vector<Item>,comp> pq;
    for(int i=0;i<k;i++) pq.push(Item(A[i][0],0,i));
    while(!pq.empty()){
        Item curr=pq.top();
        pq.pop();
        res.push_back(curr.val);
        if(curr.elemIndex<A[curr.arrIndex].size()-1) pq.push(Item(A[curr.arrIndex][curr.elemIndex+1],curr.elemIndex+1,curr.arrIndex));
    } 
    return res;
}