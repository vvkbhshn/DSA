//problem link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* res=new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0) arr[abs(arr[i])-1]*=-1;
            else res[0]=abs(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                res[1]=i+1;
                break;
            }
        }
        return res;
    }
};