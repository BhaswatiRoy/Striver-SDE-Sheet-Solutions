/*
We need to find all possible ways for reaching from (0,0) to destination (m-1,n-1) only by two possible moves - right/bottom.
Thus we can start from (0,0) and traverse through different ways to reach destination. If we reach destination then we count that path as 1 and return 1
And if we reach to a grid position after destination position then we will return 0 since it's invalid
*/

//Recursion - O(2^n) - TLE
int grid(int i, int j, int m, int n)
{
        //if we reached at destination then count that as 1 path
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        //if we cross the destination at (m-1,n-1) considering start from 0 then stop
        //and try to discover other paths
        if(i>=m || j>=n)
        {
            return 0;
        }
        //return the sum of all ways from moving to right & bottom
        return grid(i+1,j,m,n)+grid(i,j+1,m,n);
}
int uniquePaths(int m, int n) 
{
        int ans=grid(0,0,m,n);
        return ans;
}


//Memoization - O(n) - Acc
int grid(int i, int j, int m, int n, vector<vector<int>>&dp)
{
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=grid(i+1,j,m,n,dp)+grid(i,j+1,m,n,dp);
}
int uniquePaths(int m, int n) 
{
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=grid(0,0,m,n,dp);
        return ans;
}
