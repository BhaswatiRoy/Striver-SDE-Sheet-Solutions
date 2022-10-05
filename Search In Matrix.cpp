/*
A matrix with n rows and m columns can be searched using searching techniques for a search element
1. Linear Search 
   TC - O(n^2), SC - O(1)
   
2. Binary Search 
   TC - O(nlogm), SC - O(1)
*/

//linear search -> TC = n^2
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
}

//binary search -> TC= nlogm
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
        //x = column size , y = row size
        int n=matrix.size();
        int m=matrix[0].size();
        //matrix has 0 rows or 0 colums
        if(n==0 || m==0)
        {
            return false;
        }
        int left=0,right=n*m-1;
        //arr[mid] = matrix[mid/y][mid%y] 
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if (target<matrix[mid/m][mid%m])
            {
                right=mid-1;
            }
            else if(target>matrix[mid/m][mid%m])
            {
                left=mid+1;
            }
        }
        return false;
}
