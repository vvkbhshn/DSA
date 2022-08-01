//problem link: https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> res={a[0],a[0]};
    for(int i=1;i<n;i++){
        res.first=min(res.first,a[i]);
        res.second=max(res.second,a[i]);
    }
    return res;
}