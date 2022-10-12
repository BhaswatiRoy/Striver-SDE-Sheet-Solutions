/*
1. Store Inorder traversal of tree in a vector  and then the next element of key in traversal is successor & prev element of key in traversal is predecessor.
   TC - O(n), SC - O(n)
   
2. While doing inorder traversal, the 1st value that we get which is just greater than key is inorder successor, and just smaller than key is inorder predecessor.

   If current root is greater than key then we go to left and also store the successor. If current root is smaller than key then we go to left.
   
   If current root is smaller than key then we go to right and also store the predecessor. If current root is greater than key then we go to left.
   
   TC - O(n), SC - O(1)
*/

void findPre(Node*root,Node*&pre,int key)
{
    if(root==NULL)
    {
        return;
    }
    if(root->key<key)
    {
        pre=root;
        findPre(root->right,pre,key);
    }
    else
    {
        findPre(root->left,pre,key);
    }
}
void findSuc(Node*root,Node*&suc,int key)
{
    if(root==NULL) 
    {
        return;
    }
    if(root->key>key)
    {
        suc=root;
        findSuc(root->left,suc,key);
    }
    else
    {
        findSuc(root->right,suc,key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)
    {
        return;
    }
    findPre(root,pre,key);
    findSuc(root,suc,key);
}
