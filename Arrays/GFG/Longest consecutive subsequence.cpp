//problem link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

class Solution{
  public:
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int> s(arr,arr+N);
      int res=1;
      for(int i=0;i<N;i++){
         if(s.find(arr[i]-1)==s.end()){
             int cnt=0, j=arr[i];
             while(s.find(j)!=s.end()) j++;
             res=max(res,j-arr[i]);
         }
      }
      return res;
    }
};