//problem link: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

class Solution
{
    private:
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(q1.size()==q2.size()) q1.push(x);
        else q2.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(!q2.empty() && q1.top()>q2.top()){
            int x=q1.top();
            q1.pop();
            q1.push(q2.top());
            q2.pop();
            q2.push(x);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(q1.empty()) return 0;
        else if(q1.size()!=q2.size()) return q1.top();
        else if(q1.size()==q2.size()){
            return ((double)q1.top()+q2.top())/2.0;
        }
    }
};