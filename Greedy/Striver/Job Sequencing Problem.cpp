//problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

static bool myCmp(Job &a, Job &b){
    return a.profit>b.profit;
}

//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    //Greedy Solution
    int numJobs=0, maxProfit=0;
    sort(arr,arr+n,myCmp);
    int maxDeadline=0;
    for(int i=0;i<n;i++) maxDeadline=max(maxDeadline,arr[i].dead);
    vector<bool> vis(maxDeadline+1,false);
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>=1;j--){
            if(vis[j]==false){
                vis[j]=true;
                numJobs++;
                maxProfit+=arr[i].profit;
                break;
            }
        }
    }
    return {numJobs, maxProfit};
} 