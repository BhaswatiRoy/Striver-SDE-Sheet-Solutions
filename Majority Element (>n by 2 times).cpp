/*
1. Storing frequencies in hashmap and in end returning the element with frequency more than n/2 times
   TC - O(n), SC - O(n)
   
2. Boyer Moore Majority Voting Algorithm - thinking the array as a collection of votes from different candidates
                                           We increment a count variable every time we see the vote from the majority party and 
                                           decrement it whenever a vote from some other party is occured
   TC - O(n), SC - O(1)
*/

int majorityElement(vector<int>&nums) 
{
        map<int,int>mp;
        int n=nums.size(),val;
        for (auto it=nums.begin();it!=nums.end();it++)
        {
            mp[(*it)]=mp[(*it)]+1;
        }
        for (auto it=mp.begin();it!=mp.end();it++)
        {
            int count=(it->second);
            if (count>n/2)
            {
                val=(it->first);
                break;
            }
            else
            {
                continue;
            }
        }
        return val;
}

int majorityElement(vector<int>& nums) 
    {
        int count=0,majorityelem;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                majorityelem=nums[i];
            }
            if(majorityelem==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return majorityelem;
    }
