//problem link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:    
    bool isSimilar(char a, char b){
        return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(!st.empty() && isSimilar(st.top(),c)) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};