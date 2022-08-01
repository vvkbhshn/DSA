//problem link: https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int idx=0, i;
        vector<int> aux;
        for(i=0;i<n;i++){
            if(arr[i]<0) aux.push_back(arr[i]);
            else if(arr[i]>=0) swap(arr[i],arr[idx++]);
        }
        for(i=0;i<aux.size();i++){
            arr[idx++]=aux[i];
        }
    }
};