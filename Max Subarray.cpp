/*
calculate sum by traversing and if sum is greater than maximum sum then store it as maximum sum
Incase we encounter a situation where we are getting -ve sum we will replace that by 0
This is because -ve sum can never contribute to becoming a maximum sum

TC - O(n), SC - O(1)
*/
int maxSubArray(vector<int>& nums) 
{
        //Kadene's Algorithm
        int currsum=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            
            if(currsum>maxsum)
            {
                maxsum=currsum;
            }
            if(currsum<0)
            {
                currsum=0;
            }
        }
        return maxsum;
}
