//problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

void findSubsets(vector<int> &arr, vector<int> &res, int &n, int idx, int sum){
    if(idx==n){
        res.push_back(sum);
        return;
    }
    findSubsets(arr,res,n,idx+1,sum);
    findSubsets(arr,res,n,idx+1,sum+arr[idx]);
}



vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> res;
    findSubsets(arr,res,N,0,0);
    return res;
}