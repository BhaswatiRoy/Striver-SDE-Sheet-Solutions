/*
With left and right traversals if any of them is NULL then return the other one.
If both are not null then root will be returned, since both the nodes we are looking for - p,q lies under this root
This way we can keep track of last element that matched in the common path.

TC - O(n), SC - O(1)
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
        //if we found any of the nodes we will return tht node
        if(root==NULL || root==p || root==q)
        {
            return root;
        }
        //left and right traversals
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        //if left is null then return right
        if(left==NULL && right!=NULL)
        {
            return right;
        }
        //if right is null then return left
        else if(left!=NULL && right==NULL)
        {
            return left;
        }
        //if both are not null so we found the node below which p & q is present
        //this is why from one side p will be returned and from the other side q will be returned
        else if(left!=NULL && right!=NULL)
        {
            return root;
        }
        //if both are NULL then a NULL is returned
        return NULL;
}
