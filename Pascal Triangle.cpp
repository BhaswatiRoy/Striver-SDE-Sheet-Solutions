/*
1st element of 0th row will be 1
Storing 1 for 0th col of every row and then iterate from 1st col to store values according to formula

TC - O(n^2), SC - O(1)
*/
vector<vector<int>> generate(int numRows) 
{
        vector<vector<int>>pascal;
        for(int i=0;i<numRows;i++)
        {
            //storing 1 for 0th row value and all row's 0th column value
            vector<int>temp(i+1,1);
            //now starting to iterate from 1st column and store values
            for(int j=1;j<i;j++)
            {
                temp[j]=pascal[i-1][j]+pascal[i-1][j-1];
            }
            pascal.push_back(temp);
        }
        return pascal;
}
