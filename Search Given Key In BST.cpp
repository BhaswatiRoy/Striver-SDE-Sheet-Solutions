/*
traverse through the BST to find the required key element 

TC - O(n), SC - O(n)
*/

TreeNode* searchBST(TreeNode* root, int val) 
{
        if(root==NULL)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            if(temp->val==val)
            {
                return temp;
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            q.pop();
        }
        return NULL;
}
