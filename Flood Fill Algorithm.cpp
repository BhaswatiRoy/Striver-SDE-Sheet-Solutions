/*
Question - An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.

We can use DFS/BFS to do the same

TC - O(n), SC - O(n)
*/


void bfs(int i, int j, int newcolor, int initialcolor, vector<vector<int>>&image)
{
        queue<pair<int,int>>q;
        q.push({i,j});
        image[i][j]=newcolor;
        //neighbouring points are mainly {r-1,c},{r,c+1},{r+1,c},{r,c-1}
        vector<int>deltax={-1,0,+1,0};
        vector<int>deltay={0,+1,0,-1};
        while(!q.empty())
        {
            //finding row,col value of current node from queue
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            //traverse the neighbours of the given point (row,col) which is ith value of delatax & deltay vector
            for(int i=0;i<4;i++)
            {
                int newx=x+deltax[i];
                int newy=y+deltay[i];
                //checking valid (row,col) points and they should be equal to initialcolor too
                if(newx>=0 && newx<image.size() && newy>=0 && newy<image[0].size() && image[newx][newy]==initialcolor)
                {
                    q.push({newx,newy});
                    //set the valid nearby points to newcolor
                    image[newx][newy]=newcolor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int initialcolor=image[sr][sc];
        if(image[sr][sc]!=newColor)
        {
            bfs(sr,sc,newColor,initialcolor,image);
        }
        return image;
}
