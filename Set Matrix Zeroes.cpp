/*
Store (row,col) values in a vector which has any element as 0 in them
While travsering again if found that the row/col is associated with 0 them mark row/col entirely as 0
*/
void setZeroes(vector<vector<int>>& matrix) 
{
        int m=matrix.size(),n=matrix[0].size();
        //vectors to store row & column value of the elements that are 0
        vector<int>rows(m,1),cols(n,1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    //set the values as 0
                    rows[i]=0;
                    cols[j]=0;
                }
            }
        }
        for(int p=0;p<m;p++)
        {
            for(int q=0;q<n;q++)
            {
                //if the row or column value of the current element is 0 
                if(rows[p]==0 || cols[q]==0)
                {
                    //then set all elements or the current row or column as 0
                    matrix[p][q]=0;
                }
            }
        }
}
