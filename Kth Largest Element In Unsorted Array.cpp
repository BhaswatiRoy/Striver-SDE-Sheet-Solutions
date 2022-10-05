/*
1. Storing all elements in a max heap priority queue and then poping the top k-1 elements leaving us with kth largest element at top
   TC - O(nlogn), SC - O(n)
   
2. Storing all elements in a min heap priority queue and simultaneously popping elements out if size is more than k which means kth largest element will be on top
   TC - O(nlogk), SC - O(n)
*/

int findKthLargest(vector<int>& nums, int k) 
{
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        int x=k-1;
        while(x--)
        {
            pq.pop();
        }
        return pq.top();
}

int findKthLargest(vector<int>& nums, int k) 
{
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
}
