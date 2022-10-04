/*
Swap every (i,j) element with (j,i) element
Then reverse every row of the matrix to get a 90 degree rotated matrix/image
*/

void rotate(vector<vector<int>>& matrix) 
{
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int k=0;k<n;k++)
        {
            reverse(matrix[k].begin(),matrix[k].end());
        }
}
