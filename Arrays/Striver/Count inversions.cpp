//problem link: https://www.codingninjas.com/codestudio/problems/count-inversions_615

void merge(long long *arr, int l, int mid, int r, long long &inv_cnt){
	int n1=mid-l+1, n2=r-mid;
	long long a[n1], b[n2];
	for(int i=0;i<n1;i++) a[i]=arr[l+i];
	for(int i=0;i<n2;i++) b[i]=arr[mid+1+i];
	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(a[i]<=b[j]) arr[k++]=a[i++];
		else{
			arr[k++]=b[j++];
			inv_cnt+=n1-i;
		}
	}	
	while(i<n1) arr[k++]=a[i++];
	while(j<n2) arr[k++]=b[j++];
}

void mergeSort(long long *arr, int l, int r, long long &inv_cnt){
	if(l<r){
		int mid=l+(r-l)/2;
		mergeSort(arr,l,mid,inv_cnt);
		mergeSort(arr,mid+1,r,inv_cnt);
		merge(arr,l,mid,r,inv_cnt);
	}
}

long long getInversions(long long *arr, int n){
    // Write your code here
	long long inv_cnt=0;
	mergeSort(arr,0,n-1,inv_cnt);
	return inv_cnt;
}