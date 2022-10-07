/*
We can modify the height function to find maximum path sum.
If sum of any path is -ve then we will not consider that instead we will consider 0
After that pathsum of any path is leftsum+rightsum and we will keep updating simultaneously.

TC - O(n), SC - O(1)
*/

//this is finding height function modified to find max path sum also
int maxval=INT_MIN;
int maxpath(TreeNode* root)
{
        if(root==NULL)
        {
            return 0;
        }
        //if sum of left/right subtree is -ve then we will not consider that instead we will consider 0
        //considering -ve value nodes will never give us max path sum instead ignoring them will give
        //finding left path sum
        int leftsum=max(0,maxpath(root->left));
        //finding right path sum
        int rightsum=max(0,maxpath(root->right));
        
        //path sum for any given node is left path sum + right path sum + node value and update max path sum if current path sum is greater
        maxval=max(maxval,(leftsum + rightsum + root->val));
        
        return max(leftsum,rightsum) + root->val;
}

int maxPathSum(TreeNode* root) 
{
        maxpath(root);
        return maxval;
}
