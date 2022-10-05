/*
1. Sort and check if they are same string or not, since sorting anagrams give same string
   TC - O(nlogn), SC - O(1)

2. Using a map to store all chars of 1st string and then traverse through 2nd string to reduce frequency of the characters
   If at any point the frequency goes -ve then they are not anagrams
   TC - O(N), SC - O(n)/precisely O(1) as we will consider 26 alphabets only in worst case which is constant
*/

bool isAnagram(string s, string t) 
{
        if(s.length()!=t.length())
        {
            return false;
        }
        //anagrams when sorted form same string
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        if(s==t)
        {
            return true;
        }
        return false;
}

bool isAnagram(string s, string t) 
{
        if (s.size()!=t.size()) 
        {
            return false;
        }
		    unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(int j=0;j<t.length();j++)
        {
            mp[t[j]]--;
            if(mp[t[j]]<0)
            {
                return false;
            }
        }
        return true;
}
