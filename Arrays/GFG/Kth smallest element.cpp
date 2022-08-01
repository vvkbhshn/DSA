//problem link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:    
    int partition(int arr[], int l, int r){
        int pivot=arr[r], index=l;
        int i=0;
        for(i=l;i<r;i++){
            if(arr[i]<pivot) swap(arr[i],arr[index++]);
        }
        swap(arr[index],arr[r]);
        return index;
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //QuickSelect Algorithm
        while(l<=r){
            int p=partition(arr,l,r);
            if(p<k-1) l=p+1;
            else if(p>k-1) r=p-1;
            else return arr[p];
        }
        return -1;
    }
};