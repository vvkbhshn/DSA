//problem link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n;i++){
            int l=i+1, r=n-1;
            while(l<r){
                int sum=A[i]+A[l]+A[r];
                if(sum<X) l++;
                else if(sum>X) r--;
                else return true;
            }
        }
        return false;
    }
};