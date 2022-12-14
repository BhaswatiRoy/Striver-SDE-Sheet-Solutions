/*
store elements in a map and return the element that has frequency greater than 1

TC - O(n), SC - O(n)
*/

int findDuplicate(vector<int>& nums) 
{
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>1)
            {
                return it->first;
            }
        }
        return 0;
}
