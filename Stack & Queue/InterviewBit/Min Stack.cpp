//problem link: https://www.interviewbit.com/problems/min-stack/

int minEle=INT_MAX;
stack<int> s;

MinStack::MinStack() {
    minEle=INT_MAX;
    while(!s.empty()) s.pop();
}

void MinStack::push(int x) {
    if(s.empty()){
        s.push(x);
        minEle=x;
    }
    else{
        if(x<minEle){
            s.push(2*x-minEle);
            minEle=x;
        }
        else s.push(x);
    }
}

void MinStack::pop() {
    if(s.empty()) return;
    if(s.top()<minEle){
        int x=s.top();
        minEle=2*minEle-x;
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()) return -1;
    if(s.top()<minEle) return minEle;
    else return s.top();
}

int MinStack::getMin() {
    if(s.empty()) return -1;
    return minEle;
}


// Method-2: 
// stack<int> mainStack, auxStack;

// MinStack::MinStack() {
//     while(!mainStack.empty()) mainStack.pop();
//     while(!auxStack.empty()) auxStack.pop();
// }

// void MinStack::push(int x) {
//     if(auxStack.empty() || x<=auxStack.top()) auxStack.push(x);
//     mainStack.push(x);
// }

// void MinStack::pop() {
//     if(mainStack.empty()) return;
//     if(mainStack.top()==auxStack.top()) auxStack.pop();
//     mainStack.pop();
// }

// int MinStack::top() {
//     if(mainStack.empty()) return -1;
//     return mainStack.top();
// }

// int MinStack::getMin() {
//     if(mainStack.empty()) return -1;
//     return auxStack.top();
// }