//problem link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution
{
    public:    
    struct Item{
        int val, arrPos, elePos;
        Item(int a,int b,int c){
            val=a; arrPos=b; elePos=c;
        }
    };
    
    struct myCmp{
        bool operator()(Item &a, Item &b){
            return a.val>b.val;
        }
    };
    
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> res;
        priority_queue<Item,vector<Item>,myCmp> pq;
        for(int i=0;i<k;i++){
            pq.push(Item(arr[i][0],i,0));
        }
        while(!pq.empty()){
            Item curr=pq.top();
            pq.pop();
            res.push_back(curr.val);
            if(curr.elePos<arr[curr.arrPos].size()-1){
                pq.push(Item(arr[curr.arrPos][curr.elePos+1],curr.arrPos,curr.elePos+1));
            }
        }
        return res;
    }
};