//problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    
    int partition(vector<int> &arr, int l, int r){
        int pivot=arr[l], index=l;
        int i=l+1, j=r;
        while(i<=j){
            if(arr[i]<pivot && arr[j]>pivot){
                swap(arr[i++],arr[j--]);
            }    
            if(arr[i]>=pivot) i++;
            if(arr[j]<=pivot) j--;
        }
        swap(arr[l],arr[j]);
        return j;
    }
    
    int quickSelect(vector<int> &arr, int l, int r, int reqIndex){
        int index=partition(arr,l,r);
        if(index==reqIndex) return arr[index];
        else if(index<reqIndex) return quickSelect(arr,index+1,r,reqIndex);
        else return quickSelect(arr,l,index-1,reqIndex);
    }
    
    
    int findKthLargest(vector<int>& arr, int k) {
        
        // Method-1: quickSelect alogorithm [avg: O(n) time]
        int n=arr.size();
        return quickSelect(arr,0,n-1,k-1);
                
        // Method-2: minHeap [O(nlogk) time]
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(auto x:arr){
        //     pq.push(x);
        //     if(pq.size()>k) pq.pop();
        // }
        // return pq.top();
    }
};