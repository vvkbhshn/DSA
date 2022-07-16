//problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:    
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void dfs(string &digits, string &temp, int index, vector<string> &res){
        if(index==digits.length()){
            res.push_back(temp);
            return;
        }
        int num=(int)(digits[index]-'0');
        for(int i=0;i<dict[num].length();i++){
            temp+=dict[num][i];
            dfs(digits,temp,index+1,res);
            temp.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string temp="";
        dfs(digits,temp,0,res);
        return res;
    }
};