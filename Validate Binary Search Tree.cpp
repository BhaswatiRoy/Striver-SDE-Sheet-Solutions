/*
for each node we are setting a range - [minval,maxval], and if the node value doesn't lie between them return false
for left subtree checking of any node, the maxval=node val
for right subtree checking of any node, the minval=node val

TC - O(n), SC - O(1)
*/

//constraint given is from -2^31 to 2^31-1, and INT_MAX = 2^31-1 and INT_MIN = -2^31 
//thus using INT_MIN & INT_MAX will give WA in some cases
bool isbst(TreeNode* root,long long int minval,long long int maxval)
{
        if(root==NULL)
        {
            return true;
        }
        if(root->val<=minval || root->val>=maxval)
        {
            return false;
        }
        bool left=isbst(root->left,minval,root->val);
        bool right=isbst(root->right,root->val,maxval);
        return left && right;
}

bool isValidBST(TreeNode* root) 
{
        if(root==NULL)
        {
            return true;
        }
        return isbst(root,-1e18,1e18);
}
