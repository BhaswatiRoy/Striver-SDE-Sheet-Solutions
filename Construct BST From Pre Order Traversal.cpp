/*
Pre Order Traversal - Root Left Right - 1st element of vector is root of tree

1. We can traverse the vector, and keep adding elements following BST Properties. Like if 5 is root, then for adding 3 we need to add it to left and so on.
   TC - O(n^2), SC - O(1) - since we are traversing n nodes and in worst case we have to check with n nodes to add the node for a skewed tree.
   
2. Inorder traversal of BST is sorted, so we can create sort the preorder traversal to create inorder traversal. 
   Now since we have Inorder & Preorder Traversals so we can create the BT which will turn out to be a BST
   TC - O(nlogn), SC - O(1)

3. Starting with making root as 1st element and then keeping an upper bound for each element 
   going left - transferring the node -> val as upper bound
   going right - transferring previous bound as upper bound
   Preorder - [ 8 5 1 7 10 12 ]
                 8 (ub = INT_MAX)
             /                    \
      5 (ub = 8)                 10 (ub = INT_MAX)
   /            \               /                \
1 (ub = 5)     7 (ub = 8)   X (ub = 10)       12 (ub = 10)
  We can add elements only if upper bound condition is satisfied at every node - similar concept to validating BT as BST.
  TC - O(n), SC - O(1)
*/

TreeNode* constructbst(vector<int>& preorder, int &i, int bound)
{
        //if all nodes are covered / node value exceeds bound we can return
        if(i==preorder.size() || preorder[i]>bound)
        {
            return NULL;
        }
        //construct the root node
        TreeNode* root=new TreeNode(preorder[i]);
  
        //move to next node in preorder traversal
        i++;
  
        //for left subtree bound will be root->val
        root->left=constructbst(preorder,i,root->val);
        //for right subtree bound will be previous bound itself
        root->right=constructbst(preorder,i,bound);
        
        return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) 
{
        //i is pointer to traverse and go through nodes in preorder traversal
        int i=0;
        //boundary for root will be INT_MAX initially
        TreeNode *root=constructbst(preorder,i,INT_MAX);
        return root;
}
