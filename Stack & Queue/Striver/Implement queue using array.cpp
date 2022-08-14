//problem link: https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems

class Queue {
public:
    int *arr;
    int cap, size, start, end;
    
    Queue() {
        cap=5001;
        arr=new int[cap];
        size=0;
        start=0;
        end=0;
    }

    bool isEmpty() {
        return size==0;
    }

    void enqueue(int data) {
        arr[end]=data;
        end=(end+1)%cap;
        size++;
    }

    int dequeue() {
        if(isEmpty()) return -1;
        int res=arr[start];
        start=(start+1)%cap;
        size--;
        return res;
    }

    int front() {
        if(isEmpty()) return -1;
        return arr[start];
    }
};