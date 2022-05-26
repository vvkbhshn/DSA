//problem link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

class Solution
{
    public:    
    static bool myCmp(Item &a, Item &b){
        double x=(double)(a.value)/a.weight;
        double y=(double)(b.value)/b.weight;
        return x>y;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double val=0;
        sort(arr,arr+n,myCmp);
        for(int i=0;i<n;i++){
            if(arr[i].weight<W){
                val+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                val+=arr[i].value*((double)W/arr[i].weight);
                break;
            }
        }
        return val;
    }        
};