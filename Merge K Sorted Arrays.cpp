/*
Since there are k arrays of size k inside 2 d vector
For merging, we can store all elements of all k arrays in a min heap and then put those into a vector into a sorted array

TC - O(k^2logn), SC - O(k^k)
*/

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<K;j++)
            {
                pq.push(arr[i][j]);
            }
        }
        vector<int>v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
}
