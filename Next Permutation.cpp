/*
finding lexicographically smallest next permutation.
1. We find a breakpoint k such that - nums[k]<nums[k+1] traversing from back
   for arrays like {3,2,1} there is no breakpoint so simply reversing gives ans
2. for others we try to find a point l such that - nums[l]>nums[k]
3. we can then swap nums[l] & nums[k] then reverse the array after breakpoint till end
   for others like {1,2,3} k=1,l=2 - thus swapping them gives {1,3,2} 
   and then reversing from k+1 i.e 2 to end which means last index here gives {1,3,2}
*/
void nextPermutation(vector<int>& nums) 
{
        int n=nums.size(),k,l;
        //find the first break point which can be from 2nd last index to beginning
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        //if we didn't find any break point then simply reverse to get answer
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l=n-1;l>=0;l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
}
