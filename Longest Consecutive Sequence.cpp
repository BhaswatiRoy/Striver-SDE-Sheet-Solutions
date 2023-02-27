class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int len=1,maxlen=1,start=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1)
                {
                    len+=1;
                }
                else
                {
                    maxlen=max(maxlen,len);
                    len=1;
                }
            }
        }
        return max(maxlen,len);
    }
};
