/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
The next pointers of left node are connected with right nodes of same level.
The next pointers of right nodes are connected with left most node of the adjacent level.
Then recursively call the function for left and right subtrees for allocating.
TC - O(n), SC - O(1)
*/

Node* connect(Node* root) 
{
        if(root==NULL) 
        {
            return NULL;
        }
        //connects the next pointer of left node of with right node of that same level 
        if(root->left!=NULL) 
        {
            root->left->next=root->right;
        }
        //connect the rightmost node of a level to the left most node of the next level.
        if(root->right!=NULL && root->next!=NULL) 
        {
            root->right->next=root->next->left;
        }
        //recursive calls for left subtrees
        connect(root->left);
        //recursive calls for right subtrees
        connect(root->right);
        return root;
}
