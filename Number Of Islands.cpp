/*
By help of traversal techniques we can check how many connected components are present in the graph/matrix

1. DFS - fully working
   TC - O(n), SC - O(n)
   
2. BFS - not fully working on all tc
   TC - O(n), SC - O(n)
*/

//DFS
void dfstraversal(int i, int j, vector<vector<char>>&grid)
{
        //check if boundary constraints are reached or water is found then return 
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return;
        }
        //check if the point is already visited previously
        if(grid[i][j]=='2' || grid[i][j]=='0')
        {
            return;
        }
        //mark the current point as visited
        grid[i][j]='2';
        dfstraversal(i,j+1,grid);
        dfstraversal(i,j-1,grid);
        dfstraversal(i+1,j,grid);
        dfstraversal(i-1,j,grid);
}
int numIslands(vector<vector<char>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        //visited vector storing the (i,j) values that are visited
        vector<vector<int>>visited(n+1,vector<int>(m+1,0));
        int islandcount=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    islandcount++;
                    dfstraversal(i,j,grid);
                }
            }
        }
        return islandcount;
}


//BFS
void bfstraversal(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&visited)
{
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            //finding row,col value of current node from queue
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //traverse the neighbours of the given point (row,col) which is -1 to +1 of that point
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    //calculating new row,col value using delrow,delcol from current node
                    int newrow=row+delrow;
                    int newcol=col+delcol;
                    //checking valid (row,col) points and they should be land + non visited as well
                    if((newrow>=0 && newrow<n) && (newcol>=0 && newcol<m) && grid[newrow][newcol]=='1' && !visited[newrow][newcol])
                    {
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
}
    
int numIslands(vector<vector<char>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        //visited vector storing the (i,j) values that are visited
        vector<vector<int>>visited(n,vector<int>(m,0));
        int islandcount=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //the point should be land as well as unvisited before
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    islandcount++;
                    bfstraversal(i,j,grid,visited);
                }
            }
        }
        return islandcount;
}
