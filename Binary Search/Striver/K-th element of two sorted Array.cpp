//problem link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
    
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int l=min(arr1[0],arr2[0]);
    int r=max(arr1[n-1],arr2[m-1]);
    while(l<r){
        int mid=l+(r-l)/2;
        int cnt=0;
        cnt+=upper_bound(arr1,arr1+n,mid)-arr1;
        cnt+=upper_bound(arr2,arr2+m,mid)-arr2;
        if(cnt<k) l=mid+1;
        else r=mid;
    }
    return l;
}