//problem link: https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0?page=1&sortBy=newest&query=page1sortBynewest

class Solution{
  public:  
    void inorderTraversal(vector<int>&A, int n, vector<int> &inorder, int i){
        if(i>=n) return;
        inorderTraversal(A,n,inorder,2*i+1);
        inorder.push_back(A[i]);
        inorderTraversal(A,n,inorder,2*i+2);
    }
  
    int minSwaps(vector<int>&A, int n){
        int res=0;
        vector<int> inorder;
        inorderTraversal(A,n,inorder,0);
        vector<int> temp=inorder;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        sort(temp.begin(), temp.end());
        for(int i=0;i<n;i++){
            if(inorder[i]!=temp[i]){
                int idx=mp[temp[i]];
                swap(inorder[i],inorder[idx]);
                swap(mp[inorder[i]],mp[inorder[idx]]);
                res++;
            }
        }
        return res;
    }  
};