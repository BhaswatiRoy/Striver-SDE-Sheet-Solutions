/*
Profit is value/weight ratio and thus we are sorting the vector of pairs - {value,weight} based on value/weight
The sorting is done in descending order, so that we grab the higher profit items before 
We can also break items/completely take one item to fill the knapsack

TC - O(nlogn), SC - O(n)
*/

//comparator function to sort on basis of value/weight
static bool comparator(pair<double,int> a,pair<double,int> b)
{
        double r1=(double)a.first/a.second;
        double r2=(double)b.first/b.second;
        return r1>r2;
}

//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].value,arr[i].weight});
        }
        //sort in descending order
        sort(v.begin(),v.end(),comparator);
        int currwt=0;
        double profit=0.0;
        //first = value , second = weight
        for(int j=0;j<n;j++)
        {
            //completely pick the item
            if(currwt+v[j].second<=W)
            {
                currwt+=v[j].second;
                profit+=v[j].first;
            }
            else
            {
                //remaining weight in knapsack
                int remwt=W-currwt;
                profit+=(v[j].first/v[j].second)*remwt;
                //since now we have completely filled our knapsack so no more space remains
                break;
            }
        }
        return profit;
}
