/*
We need to recursively traverse to left/right
If both nodes lie on left subtree then traverse to left subtree
If both nodes lie on right subtree then traverse to right subtree
If one lies on left & another lies on right then we reached to a node which is the point of disection and must be LCA

TC - O(n), SC - O(1)
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
        if(root==NULL)
        {
            return NULL;
        }
        //if both p & q lies on right
        if(root->val<p->val && root->val<q->val)
        {
            //traverse to right
            return lowestCommonAncestor(root->right,p,q);
        }
        //if both p & q lies on left
        if(root->val>p->val && root->val>q->val)
        {
            //traverse to left
            return lowestCommonAncestor(root->left,p,q);
        }
        //else one lies on left and one lies on right so the root must be the last point of intersection from top and first point of intersection from bottom
        return root;
}
