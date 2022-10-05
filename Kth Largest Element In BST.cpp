/*
1. Level Order Traversal and store elements in array and then sort them and return (n-k)th index elements
   TC - O(nlogn), SC - O(n)
   
2. Inorder Traversal and store elements in array, we don't need to sort as inorder traversal of BST gives elements in sorted order and return (n-k)th index elements
   TC - O(n), SC - O(n)
*/

vector<int>v;
void levelorder(TreeNode* root)
{
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            v.push_back(temp->val);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
}
int kthLargest(TreeNode *root, int K)
{
        levelorder(root);
        sort(v.begin(),v.end());
        int n=v.size();
        //vector is 0 index and position is 1 index
        return v[n-k];
}


vector<int>v;
void inorder(TreeNode* root)
{
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
}
int kthLargest(TreeNode *root, int k)
{
        inorder(root);
        int n=v.size();
        return v[n-k];
}
