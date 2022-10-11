/*
We will iterate through spaces until we reach an alphabet to start a word. 
Once reached we will again traverse to reach to end of the word which is a space/end of string. 
Then we will consider the subtring from ith to jth index and consider the word. Then append in front of resultant string to get in reversed order.

TC - O(n), SC - O(1)
*/

string reverseWords(string s) 
{
        string ans="";
        int i,j,n=s.length();
        i=0;
        while(i<n)
        {
            //not include spaces and break when we reach to an alphabet i.e word starts
            while(i<n && s[i]==' ')
            {
                i++;
            }
            //j marks start of a word
            j=i;
            //when we do not reach a space, means we are currently on a word
            //j finds till how much the word is present
            while(j<n && s[j]!=' ')
            {
                j++;
            }
		        //now j is used to find end of the word so that each word is treated as a substring
            //and appending in front of resultant string to get in reversed order
            ans=" "+s.substr(i,j-i)+ans;
            //once done i is incremented to j i.e end of word so that it starts for next word
            i=j+1;
        }
        //loop to remove leading spaces
        i=0;
        while(i<n && ans[i]==' ')
        {
            i++;
        }
        //now i is at position where leading 0 end and alphabets starts
        //so we will start from i and take entire of remaining string
        ans=ans.substr(i);
        return ans;
}
