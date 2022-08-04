//problem link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

bool findPair(int arr[], int size, int n){
    // Method-1:
    sort(arr,arr+size);
    int i=0, j=1;
    while(i<size && j<size){
        int diff=arr[j]-arr[i];
        if(diff==n && i!=j) return true;
        else if(diff>n) i++;
        else j++;
    }
    return false;
    
    
    // Method-2:
    // unordered_set<int> s;
    // for(int i=0;i<size;i++){
    //     if(s.find(arr[i]+n)!=s.end() || s.find(arr[i]-n)!=s.end()) return true;
    //     s.insert(arr[i]);
    // }
    // return false;
}