/*
Go to absolute end of right subtree and set the last node as prev, then recursively come back and set prev to last finished node
This way we will keep on finishing nodes and our linked list will be ready

TC - O(n), SC - O(1)
*/

//prev stores the last completed node
//as soon as left & right traversals of any node is completed it is stored in prev
TreeNode* prev=NULL;
void flatten(TreeNode* root) 
{
        if(root==NULL)
        {
            return;
        }
        //goes to absolute right
        flatten(root->right);
  
        //then goes to absolute left
        flatten(root->left);
  
        //set right link of current node to prev completed node
        root->right=prev;
  
        //set left link of current node to NULL as this will be a right skewed tree
        root->left=NULL;
  
        //update prev as the current completed node
        prev=root;
}
