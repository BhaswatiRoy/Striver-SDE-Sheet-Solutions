/*
Balanced Height BT - BT has the absolute difference between left and right subtree is <=1. If all nodes of BT are balanced then entire tree is balanced
                   
For every node we will check if all the left and right subtrees are balanced or not and then we will for that node the absolute diff between heights of
both left and right subtree is <=1 or not
*/

int height(TreeNode* root)
{
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        //max of both is taken and +1 for root
        int ht=max(lh,rh)+1;
        
        return ht;
}
bool isBalanced(TreeNode* root) 
{
        if(root==NULL)
        {
            return true;
        }
        //if any of the node either in left or right subtree is unbalanced
        //then entire tree is unbalanced
        if(isBalanced(root->left)!=true)
        {
            return false;
        }
        if(isBalanced(root->right)!=true)
        {
            return false;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        if(abs(lefth-righth)<=1)
        {
            return true;
        }
        return false;
}
