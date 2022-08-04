//problem link: https://practice.geeksforgeeks.org/problems/common-elements1132/1

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> res;
            int i=0,j=0,k=0;
            while(i<n1 && j<n2 && k<n3){
               while(i>0 && i<n1 && A[i]==A[i-1]) i++;
               while(j>0 && j<n2 && B[j]==B[j-1]) j++;
               while(k>0 && k<n3 && C[k]==C[k-1]) k++;
               if(A[i]==B[j] && B[j]==C[k]){
                   res.push_back(A[i]);
                   i++; j++; k++;
               }
               else if(A[i]<B[j]) i++;
               else if(B[j]<C[k]) j++;
               else k++;
            }
            return res;
        }
};