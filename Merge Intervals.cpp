/*
We have to merge intervals [a1,b1] & [a2,b2] if a2<=b1
Thus firstly we have to sort it and then check the condition and merge them accordingly
While merging the greater value of b1 and b2 becomes the end value of merged interval and a1 remains the start value of merged interval

TC - O(nlogn), SC - O(n)
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>ans;
        if(intervals.size()==0)
        {
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        //marking 1st interval as a pair - temp to compare 
        vector<int>temp=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            //if we get an interval to merge then we merge it and go ahead
            if(intervals[i][0]<=temp[1])
            {
                temp[1]=max(intervals[i][1],temp[1]);
            }
            //otherwise we push the last pair - temp and make current pair as temp for further comparisions
            else
            {
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        //lastly add the last remaining temp value in the end
        ans.push_back(temp);
        return ans;
    }
