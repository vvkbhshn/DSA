//problem link: https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.length(), n=b.length();
        int carry=0;
        int i=m-1, j=n-1;
        string res="";
        while(i>=0 || j>=0 || carry>0){
            int sum=0;
            if(i>=0 && a[i]=='1') sum++;
            if(j>=0 && b[j]=='1') sum++;
            sum+=carry;
            carry=sum/2;
            sum=sum%2;
            if(sum==0 || sum==2) res+='0';
            else res+='1';
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};