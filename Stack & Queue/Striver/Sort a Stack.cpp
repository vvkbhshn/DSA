//problem link: https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems

void sortStack(stack<int> &s){
	if(s.empty()) return;
    int curr=s.top();
    s.pop();
    sortStack(s);
    stack<int> aux;
    while(!s.empty() && s.top()>curr){
        aux.push(s.top());
        s.pop();
    }
    s.push(curr);
    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }
}