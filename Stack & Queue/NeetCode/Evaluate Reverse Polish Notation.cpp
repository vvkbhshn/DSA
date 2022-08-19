//problem link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token:tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int val;
                if(token=="+") val=b+a;
                else if(token=="-") val=b-a;
                else if(token=="*") val=b*a;
                else val=b/a;
                s.push(val);
            }
            else s.push(stoi(token));
        }
        return s.top();
    }
};