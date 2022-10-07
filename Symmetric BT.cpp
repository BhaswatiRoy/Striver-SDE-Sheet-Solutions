/*
To check if a BT check is a mirror of itself (i.e., symmetric around its center).
We can use the Same Tree logic to check
The same tree logic can be applied to subtrees of any node to check - 1st subtree should be mirror of 2nd subtree
thus left part will be compared with right part & right part will be compared with left part

TC - O(n), SC - O(1)
*/

bool samesubtree(TreeNode* p, TreeNode* q)
{
        if(p==NULL && q==NULL)
        {
            return true;
        }
        else if(p==NULL || q==NULL)
        {
            return false;
        }
        else if(p->val!=q->val)
        {
            return false;
        }
        
        return samesubtree(p->left,q->right) && samesubtree(p->right,q->left);
}

bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        bool ans=samesubtree(root->left,root->right);
        return ans;
    }
