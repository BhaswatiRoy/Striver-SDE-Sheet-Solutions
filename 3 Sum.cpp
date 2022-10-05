/*

*/

vector<vector<int>> threeSum(vector<int>& nums) 
{
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        //a+b+c=0 -> (b+c)=(-a)
        //move this loop for finding a
        for(int i=0;i<n-2;i++)
        {
            //if a is at 0th index then there is no element before it so need to check duplicates
            //but if a is not at 0th index we need to check duplicates with previous index
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                //low will start at next index of i and high from last index
                //sum = -(a) = -(nums[i])
                //low = b, high = c
                int low=i+1,high=n-1,sum=-(nums[i]);
                while(low<high)
                {
                    //if b+c is equal to sum then we can add that into our ans
                    if(nums[low]+nums[high]==sum)
                    {
                        ans.push_back({nums[i],nums[low],nums[high]});
                        //and we can also increment b upto a point where we find different elements to avoid duplicates
                        while(low<high && nums[low]==nums[low+1])
                        {
                            low++;
                        }
                        //and we can also decrement c upto a point where we find different elements to avoid duplicates
                        while(low<high && nums[high]==nums[high-1])
                        {
                            high--;
                        }
                        low++;
                        high--;
                    }
                    //since vector is sorted and b+c is less than sum so we need to increment b
                    else if(nums[low]+nums[high]<sum)
                    {
                        low++;
                    }
                    //since vector is sorted and b+c is more than sum so we need to decrement c
                    else if(nums[low]+nums[high]>sum)
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
}
