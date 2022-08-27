//problem link: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;    
public:
    MedianFinder() {
        
    }
        
    void addNum(int num) {
        if(left.empty()) left.push(num);
        else if(left.size()==right.size()){
            if(num>right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else left.push(num);
        }
        else{
            if(num<left.top()){
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else right.push(num);
        }
    }
    
    double findMedian() {
        if(left.size()!=right.size()) return left.top();
        return ((double)left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */