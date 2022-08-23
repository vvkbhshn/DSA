//problem link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:    
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        this->k=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */