int main() {
	//problem link: https://practice.geeksforgeeks.org/problems/reverse-an-array/0
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0,j=n-1; i<j; i++, j--) swap(arr[i],arr[j]);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<'\n';
    }
	return 0;
}