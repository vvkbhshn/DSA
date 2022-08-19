//problem link: https://leetcode.com/problems/min-stack/

//O(1) method is to replace x by 2*x-min (https://leetcode.com/submissions/detail/774259673/)

class MinStack {
private:
    stack<int> mainStack, auxStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(auxStack.empty() || auxStack.top()>=val) auxStack.push(val);
    }
    
    void pop() {
        if(auxStack.top()==mainStack.top()) auxStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return auxStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */