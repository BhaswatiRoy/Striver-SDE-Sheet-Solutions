/*
Question - You are given an m x n grid where each cell can have one of three values:
           0 = empty cell, 1 = a fresh orange, 2 = a rotten orange.
           Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
           Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
           
First we can store all oranges that are already rotten from beginning in a queue and using BFS traversal we can traverse to nearly 4 grids and rot the fresh oranges
We will also count the total fresh oranges in beginning.
Again while rotting we will count how many oranges did we rot and if the count is not same as total fresh oranges in beginning we will return -1

TC - O(n*m), SC - O(n*m)
*/

int orangesRotting(vector<vector<int>>& grid) 
{
        int n = grid.size();
        int m = grid[0].size();
        //queue storing - {{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        //create the visited array
        vector<vector<int>>visited(n,vector<int>(m,0));
        int totalfresh = 0;
        //store all the oranges that are already rotten from beginning
        for (int i=0;i<n;i++) 
        {
            for (int j=0;j<m;j++) 
            {
                //if cell contains rotten orange then push into queue
                if (grid[i][j] == 2) 
                {
                    q.push({{i, j}, 0}); 
                    // mark as visited (rotten) in visited array
                    visited[i][j] = 2;
                }
                //if not rotten
                else 
                {
                    visited[i][j] = 0;
                }
                //count fresh oranges in beginning
                if (grid[i][j] == 1)
                {
                    totalfresh++;
                }
            }
        }
        int maxtime = 0;
        //to find neighboring grids
        vector<int>delrow={-1, 0, +1, 0};
        vector<int>delcol={0, 1, 0, -1}; 
        int rottcount = 0;
        while (!q.empty()) 
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            //store the maximum time taken to rott all the oranges
            maxtime=max(maxtime,time);
            q.pop();
            // exactly 4 neighbours 
            for (int i=0;i<4;i++) 
            {
                // neighbouring row and column
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                //check for valid cell and  then for unvisited fresh orange
                if (newrow>=0 && newrow<n && newcol>=0 && newcol<m && visited[newrow][newcol]==0 && grid[newrow][newcol]==1) 
                {
                   //push in queue with timer increased
                   q.push({{newrow, newcol}, time+1}); 
                   //mark as rotten in visited vector
                   visited[newrow][newcol] = 2;
                   //keep a count of all the valid oranges that are rotten
                   rottcount++;
                }
             }
        }
        //if in end all the rotten oranges count is not equal to total fresh oranges in beginning
        //then all oranges are not successfully rotten
        if (rottcount!=totalfresh) 
        {
            return -1;
        }
        return maxtime;
}
