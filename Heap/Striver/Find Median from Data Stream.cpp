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
            if(num<=right.top()) left.push(num);
            else{
                int temp=right.top();
                right.pop();
                left.push(temp);
                right.push(num);
            }
        }
        else{
            if(num>=left.top()) right.push(num);
            else{
                int temp=left.top();
                left.pop();
                right.push(temp);
                left.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.empty()) return 0;
        else if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        else return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */