/*
We can sort the job based on profit so that we can maximize the profit.
And we can first sort the jobs accoridng to profits in descending order.
Now we can perform a job in the last day of deadline so that we can maximise the jobs done.

We can also keep a vector to mark which job is to be done on which day and initially set to -1.
If on any day we see a job is already being done then we can move backwards and check other days for the job.

TC - O(nlogn), SC - O(n)
*/

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

//comparator function to sort the structure Job
static bool comparator(Job a, Job b)
{
        return (a.profit>b.profit);
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
        //the elements of structure are - Job Id(id), Deadline(dead), Profit(profit)
        //so we can accesss respective elements by - .id, .dead, .profit
        vector<int>done(n,-1);
        sort(arr,arr+n,comparator);
        int day=0,profit=0;
        for(int i=0;i<n;i++)
        {
            //it might happen that deadline is >=n and in that case we have to take n
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j]==-1)
                {
                    day+=1;
                    profit+=arr[i].profit;
                    done[j]=1;
                    break;
                }
            }
        }
        return {day,profit};
}
