/*
Store the frequency of all elements in a map
Then store frequencies,element into a max heap and then pop top k values and store them

TC - O(n), SC - O(n)
*/

vector<int> topKFrequent(vector<int>& nums, int k) 
{
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            //pair -> frequency,element
            pq.push({it->second,it->first});
        }
        vector<int>v;
        while(k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
}
