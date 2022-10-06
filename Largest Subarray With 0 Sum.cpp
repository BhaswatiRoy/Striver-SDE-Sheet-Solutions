/*
1,-1,3,2,0,-2 - upto 2nd index we have sum=3 and upto 5th index we also have sum=3, this means 3rd to 5th index has sum=0
so everytime we encounter a same sum as we did before at some index then there is a possibility of getting a subarray with sum=0

If the sum is not found in map then we will add (sum,index upto which sum is counted) in map
And if the sum is found in map then (current index - last index where sum was same) is length of subarray with sum 0

TC - O(n), SC -O(n)
*/

int maxLen(vector<int>&A, int n)
{   
        int sum=0,maxlen=0;
        unordered_map<int,int>mp;
        for(int i=0;i<A.size();i++)
        {
            sum+=A[i];
            //if at some point we get sum as 0 then we will update maxlength there also
            if(sum==0)
            {
                maxlen=i+1;
            }
            //if the sum till now is not found before we can store in map
            //we store as (sum,index upto which sum is counted)
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
            //if sum is found in map this means at some point sum was same as now
            //1,-1,3,2,0,-2 -> sum upto 2nd index and sum upto 5th index are same
            //this is because 2-2=0 sum which can be taken into count
            //length - (current index - last index where sum was same)
            else
            {
                maxlen=max(maxlen,(i-mp[sum]));
            }
        }
        return maxlen;
}
