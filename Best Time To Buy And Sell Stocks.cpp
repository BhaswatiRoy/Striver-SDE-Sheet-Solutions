/*
Traversing the entire array and finding the current minimum price by comparing each time
Later comparing the current profit and maximum profit to get optimal maximum profit value

TC - O(n), SC - O(1)
*/

int maxProfit(vector<int>& prices) 
{
        int maxprofit=INT_MIN,minprice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            //if current price is less than min price then set that to min price
            if(prices[i]<minprice)
            {
                minprice=prices[i];
            }
            //if current profit is more than max profit then set that to max profit
            if(abs(prices[i]-minprice)>maxprofit)
            {
                maxprofit=prices[i]-minprice;
            }
        }
        return maxprofit;
}
