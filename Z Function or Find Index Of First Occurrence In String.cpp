/*
finding 1st occurence of string needle in string haystack can be iterating amongst haystack and check if substring needle is present anywhere or not

TC - O(n+m), SC - O(1)
*/

int strStr(string haystack, string needle) 
{
        int n=haystack.size(),m=needle.size();
        if(m==0)
        {
            return 0;
        }
        if(n<m)
        {
            return -1;
        }
        //iterate upto n-m indices as substr checks upto next m indices 
        for(int i=0;i<=n-m;i++)
        {
            string str=haystack.substr(i,m);
            if(str==needle)
            {
                return i;
            }
        }
        return -1;
}
