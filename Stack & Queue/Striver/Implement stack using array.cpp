//problem link: https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209

class Stack {
    
public:
    int *arr;
    int cap, size, rear;
    
    Stack(int capacity) {
        arr=new int[capacity];
        cap=capacity;
        size=0;
        rear=0;
    }

    void push(int num) {
        if(isFull()) return;
        arr[size]=num;
        size++;
    }

    int pop() {
        if(isEmpty()) return -1;
        int res=arr[size-1];
        size--;
        return res;
    }
    
    int top() {
        if(isEmpty()) return -1;
        return arr[size-1];
    }
    
    int isEmpty() {
        return size==0;
    }
    
    int isFull() {
        return size==cap;
    }    
};