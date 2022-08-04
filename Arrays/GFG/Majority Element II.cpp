//problem link: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr;
        int num1=-1, num2=-1, cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==num1) cnt1++;
            else if(arr[i]==num2) cnt2++;
            else if(cnt1==0){
                num1=arr[i];
                cnt1=1;
            }
            else if(cnt2==0){
                num2=arr[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        cnt1=cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==num1) cnt1++;
            if(arr[i]==num2) cnt2++;
        }
        if(cnt1>n/3) res.push_back(num1);
        if(num1!=num2 && cnt2>n/3) res.push_back(num2);
        return res;
    }
};