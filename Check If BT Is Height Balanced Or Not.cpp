/*
Balanced Height BT - BT has the absolute difference between left and right subtree is <=1. If all nodes of BT are balanced then entire tree is balanced
                   
1.  Every node we will check if all the left and right subtrees are balanced or not and then we will for that node the absolute diff between heights of
    both left and right subtree is <=1 or not. Since for each node again we are checking height so n^2
    TC - O(n^2), SC - O(1)
    
2.  We can merge the height and traversing function, so that within the height function we checked the balanced form and reduce the complexity
    TC - O(n), SC - O(1)
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
        //if any of the node either in left or right subtree of the current node is unbalanced then entire tree is unbalanced
        if(root==NULL)
        {
            return true;
        }
        //checking for left subtree
        if(isBalanced(root->left)!=true)
        {
            return false;
        }
        //checking for right subtree
        if(isBalanced(root->right)!=true)
        {
            return false;
        }
        //finding left and right heights
        int lefth=height(root->left);
        int righth=height(root->right);
        //checking the absolute differences of left and right subtree heights of the current node
        if(abs(lefth-righth)<=1)
        {
            return true;
        }
        return false;
}



bool ans;
int checkbalance(TreeNode* root)
{
        if(root==NULL)
        {
            return 0;
        }
        int lefth=checkbalance(root->left);
        int righth=checkbalance(root->right);
        if (abs(lefth-righth)>1)
        {
            ans=false;
        }
        return 1+max(lefth,righth);
}
bool isBalanced(TreeNode* root) 
{
        ans=true;
        checkbalance(root);
        return ans;
}
