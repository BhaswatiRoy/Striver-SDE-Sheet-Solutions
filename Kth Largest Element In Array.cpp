/*
Use a max heap to store all elements into it and then pop the k-1 largest elements
This leaves us with kth largest element in the heap

TC - O(nlogn), SC - O(n)
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
