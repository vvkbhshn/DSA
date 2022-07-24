//problem link: https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> res;
    vector<int> heap;
    int size=0;
    for(auto &v:q){
        if(v[0]==0){
            heap.push_back(v[1]);
            size++;
            int i=size-1;
            while(i!=0 && heap[(i-1)/2]>heap[i]){
                swap(heap[(i-1)/2],heap[i]);
                i=(i-1)/2;
            }
        }
        else{
            res.push_back(heap[0]);
            swap(heap[0],heap[size-1]);
            size--;
            heap.pop_back();
            
            //HEAPIFY(0) operation
            int i=0;
            while(i<size){
                int smallest=i;
                if(2*i+1<size && heap[2*i+1]<heap[smallest]) smallest=2*i+1;
                if(2*i+2<size && heap[2*i+2]<heap[smallest]) smallest=2*i+2;
                if(smallest!=i){
                    swap(heap[i],heap[smallest]);
                    i=smallest;
                }
                else break;
            }
        }
    }
    return res;
}
