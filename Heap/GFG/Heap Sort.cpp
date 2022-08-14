//problem link: https://practice.geeksforgeeks.org/problems/heap-sort/1

class Solution
{
    public:    
    int left(int i){
        return 2*i+1;
    }
    
    int right(int i){
        return 2*i+2;
    }
    
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i){
        int largest=i;
        if(left(i)<n && arr[left(i)]>arr[i]) largest=left(i);
        if(right(i)<n && arr[right(i)]>arr[largest]) largest=right(i);
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n){ 
        for(int i=(n-2)/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        buildHeap(arr,n);
        for(int i=n-1;i>=1;i--){
           swap(arr[0],arr[i]);
           heapify(arr,i,0);
        }
    }
};