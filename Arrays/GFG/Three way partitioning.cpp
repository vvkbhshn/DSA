//problem link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int n=arr.size();
        int i=0,j=0,k=n-1;
        while(j<=k){
            if(arr[j]<a){
                swap(arr[i++],arr[j++]);
            }
            else if(arr[j]>b){
                swap(arr[j],arr[k--]);
            }
            else j++;
        }
    }
};