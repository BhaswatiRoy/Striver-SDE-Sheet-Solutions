/*
We can use sliding window to traverse through the string and also store frequency of string. 
If frequency of any character is more than 1 then we can reduce length of substring until we get frequency as 1. 
Then once we get all frequencies as 1 we store it in a maximum length variable

TC - O(n), SC - O(n)
*/

int lengthOfLongestSubstring(string s) 
{
        unordered_map<char,int>mp;
        int i=0,j=0,n=s.length(),maxlen=0;
        while(j<n)
        {
            //store frequency of current element of string in map
            mp[s[j]]++;
            //if the character is not occuring only once then reduce the frequency and increment start pointer of window
            while(mp[s[j]]!=1)
            {
                mp[s[i]]--;
                i++;
            }
            //compare current window size & max window size
            maxlen=max(maxlen,j-i+1);
            //increment end pointer of window
            j++;
        }
        return maxlen;      
}
