/*
Store all elements in a min heap and remove elements if the no of elements exceed size k

TC - O(nlogk), SC - O(k)
*/

int kval;
priority_queue<int,vector<int>,greater<int>>pq;
KthLargest(int k, vector<int>& nums) 
{
        kval=k;
        //put elements into the min heap
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            //since we want kth larget element, we pop elements from pq if its size > k
            if(pq.size()>kval)
            {
                pq.pop();
            }
        }
}
    
int add(int val) 
{
        pq.push(val);
        //if after pushing this element size > k then again we will pop
        //so that top element remains the kth largest one
        if(pq.size()>kval)
        {
            pq.pop();
        }
        return pq.top();
}
