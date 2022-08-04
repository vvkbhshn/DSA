class Solution{
  public:
    
    long long mergeSort(long long arr[], int l, int r){
        long long cnt=0;
        if(l<r){
            int mid=l+(r-l)/2;
            cnt+=mergeSort(arr,l,mid);
            cnt+=mergeSort(arr,mid+1,r);
            //merge
            int m=mid-l+1, n=r-mid;
            vector<long long> a(m), b(n);
            for(int i=l;i<=mid;i++) a[i-l]=arr[i];
            for(int i=mid+1;i<=r;i++) b[i-mid-1]=arr[i];
            int i=0, j=0, index=l;
            while(i<m && j<n){
                if(a[i]<=b[j]) arr[index++]=a[i++];
                else if(a[i]>b[j]){
                    cnt+=m-i;
                    arr[index++]=b[j++];
                }
            }
            while(i<m) arr[index++]=a[i++];
            while(j<n) arr[index++]=b[j++];
        }
        return cnt;
    }
    
    
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    }

};