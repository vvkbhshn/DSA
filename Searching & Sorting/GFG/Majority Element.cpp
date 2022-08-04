//problem link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        //Moore's Voting Algorithm
        int num=-1, cnt=1;
        for(int i=0;i<n;i++){
            if(a[i]==num) cnt++;
            else{
                cnt--;
                if(cnt==0){
                    num=a[i];
                    cnt=1;
                }
                
            }
        }
        cnt=0;
        for(int i=0;i<n;i++) if(a[i]==num) cnt++;
        return (cnt>n/2) ? num : -1;
    }
};