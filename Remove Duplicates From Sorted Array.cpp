/*
1. Store elements in a set to get number of distinct elements
   TC - O(nlogn), SC - O(n)
   
2. Use two pointers - i,j - i keeps track of last distinct element index and j keeps iterating through all elements
   Everytime, j finds a distinct element it replaces it with last position of i
   TC - O(n), SC - O(1)
*/

int removeDuplicates(vector<int>&nums) 
{
        set<int>s;
        for (auto it=nums.begin();it!=nums.end();it++)
        {
            s.insert(*it);
        }
        nums.clear();
        for (auto it=s.begin();it!=s.end();it++)
        {
            nums.push_back(*it);
        }
        return nums.size();
}

int removeDuplicates(vector<int>& nums) 
{
        //i keeps track of distinct elements
        int i=0;
        //j keeps iterating on all elements
        for(int j=1;j<nums.size();j++)
        {
            //everytime j finds a distinct element it replaces it with last position of i
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
}
