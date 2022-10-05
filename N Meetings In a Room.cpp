/*
We can store pairs {endtime,starttime} in vectors, and sort them in ascending order i.e order of endtime
This way we can see if starttime of next activity is more than endtime of prev activity
This helps us to count how many total n activities can take place without clashing with each other
*/


int maxMeetings(int start[], int end[], int n)
{
        vector<pair<int,int>>activity;
        for(int i=0;i<n;i++)
        {
            //0th index=end, 1st index=start
            activity.push_back({end[i],start[i]});
        }
        sort(activity.begin(),activity.end());
        //limit is end time of an activity
        int limit=activity[0].first,count=1;
        for(int i=1;i<n;i++)
        {
            //if start time of next activity is more than end time of prev activity then only we can do that
            if(activity[i].second>limit)
            {
                limit=activity[i].first;
                count++;
            }
        }
        return count;
}
