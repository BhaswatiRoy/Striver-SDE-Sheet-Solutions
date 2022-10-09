/*
Coin Change Problem 2 - Find maximum no of coin combinations that can be made of different denominations given to represent the total amount of money
                        Similar to unbounded knapsack as we can pick multiple same denomination coins. Similar to count no of subsets as we have to count combinations.
                        
                        We can recursively solve this, in knapsack approach, i.e if value is less than or equal to amount then we can try to pick it otherwise can't.
                        If amount after reduction by picking coins comes to 0 we can count that into our no of ways
*/

//TC=O(2^n), SC=O(1)
int noofwaysrecursion(vector<int>&coins,int amount,int n)
{
	//if we have no coins then we can't make any amount
	if(n==0)
	{
		return 0;
	}
	//if amount is 0 then we can always form that amount by taking no coins
	if(amount==0)
	{
		return 1;
	}
	//if coin value is less than or equal to amount then we can either pick it or not pick it
	//similar to unbounded knapsack pick is unprocessed & not pick is processed
	//also similar to count no of subsets we used "+" instead of "max"
	if(coins[n-1]<=amount)
	{
		return noofwaysrecursion(coins,amount-coins[n-1],n)+noofwaysrecursion(coins,amount,n-1);
	}
	//if coin value is more than the amount then we can not pick it
	else
	{
		return noofwaysrecursion(coins,amount,n-1);
	}
}

//TC=O(n), SC=O(n^2)
int noofwaysmemoization(vector<int>&coins,int amount,int n,vector<vector<int>>&dp)
{
	if(n==0)
	{
		return 0;
	}
	if(amount==0)
	{
		return 1;
	}
	if(dp[n][amount]!=-1)
    {
        return dp[n][amount];
    }
	if(coins[n-1]<=amount)
	{
		return dp[n][amount]=noofwaysmemoization(coins,amount-coins[n-1],n,dp)+noofwaysmemoization(coins,amount,n-1,dp);
	}
	else
	{
		return dp[n][amount]=noofwaysmemoization(coins,amount,n-1,dp);
	}
}
