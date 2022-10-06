/*
recursively find the heights of left and right subtrees and return the highest amongst both +1
Highest height will be the height of the entire tree and +1 is done for the root of any point as it is not counted in subtrees

TC - O(n), SC - O(1)
*/

int maxDepth(TreeNode* root) 
{
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            int a=maxDepth(root->left);
            int b=maxDepth(root->right);
            if(a>b)
            {
                return a+1;
            }
            else
            {
                return b+1;
            }
        }
        return 0;
}
