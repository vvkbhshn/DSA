//problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
private:
    vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:    
    void findCombinations(string &digits, vector<string> &res, string &curr, int index){
        if(index==digits.length()){
            res.push_back(curr);
            return;
        }
        int num=digits[index]-'0';
        for(int i=0;i<phone[num].length();i++){
            curr+=phone[num][i];
            findCombinations(digits,res,curr,index+1);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string curr="";
        findCombinations(digits,res,curr,0);
        return res;
    }
};