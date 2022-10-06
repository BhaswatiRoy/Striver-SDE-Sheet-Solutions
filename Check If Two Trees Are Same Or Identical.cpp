/*
Both trees are traversed together and checked if any any point we get a F or not.
If not then the trees are identical

TC - O(n), SC - O(1)
*/

bool isSameTree(TreeNode* p, TreeNode* q) 
{
        //since both are null then they can be identical so we can return T
        //this basically means that traversals reached to leaves and didn't get a F yet
        if(p==NULL && q==NULL)
        {
            return true;
        }
        //if any one of them is null and not the other then they can't be identical so we can return F
        else if(p==NULL || q==NULL)
        {
            return false;
        }
        //if values between same nodes of two trees are different then also return false
        else if(p->val!=q->val)
        {
            return false;
        }
        //if both left and right subtree traversals return T then they are same otherwise not
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
