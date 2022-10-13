/*
Maximum Sum Increasing Subsequence - Find the sum of the longest subsequence that is strictly increasing
v1 = [ 0 1 0 3 2 3 ], v2 = [ 0 1 2 3 ] -> after storing in set
Now LCS of both will give us longest increasing subsequence - 0 1 2 3 which has length = 4

Now this is slight variation of LIS problem, we have to return sum instead of length, so instead of +1 we do + v1[n-1]
*/


int lisrecursion(int n,int m,vector<int>&v1,vector<int>&v2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(v1[n-1]==v2[m-1])
    {
        return v1[n-1]+lisrecursion(n-1,m-1,v1,v2);
    }
    else
    {
        return max(lisrecursion(n-1,m,v1,v2),lisrecursion(n,m-1,v1,v2));
    }
}

int lismemoization(int n,int m,vector<int>&v1,vector<int>&v2,vector<vector<int>>&dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(v1[n-1]==v2[m-1])
    {
        return dp[n][m]=v1[n-1]+lismemoization(n-1,m-1,v1,v2,dp);
    }
    else
    {
        return dp[n][m]=max(lismemoization(n-1,m,v1,v2,dp),lismemoization(n,m-1,v1,v2,dp));
    }
}

int maxSumIS(int arr[], int n)  
{  
	    set<int>st;
	    vector<int>v1,v2;
	    for(int i=0;i<n;i++)
	    {
	        st.insert(arr[i]);
	        v1.push_back(arr[i]);
	    }
	    for(auto it=st.begin();it!=st.end();it++)
      {
            v2.push_back(*it);
      }
      int m=v2.size();
      int ans1=lisrecursion(n,m,v1,v2);
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      int ans2=lismemoization(n,m,v1,v2,dp);
      
}
