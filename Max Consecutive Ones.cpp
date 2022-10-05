/*
If we find a 1 then increase count by 1 and consecutively store it in maxcount if needed
And if we get a 0 then make count as 0 and start fresh

TC - O(n), SC - O(1)
*/

int findMaxConsecutiveOnes(vector<int>& nums) 
{
        int count=0,maxcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
                maxcount=max(count,maxcount);
            }
            else if(nums[i]==0)
            {
                count=0;
            }
        }
        return maxcount;
}
