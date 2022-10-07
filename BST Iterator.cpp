/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.

TC - O(n), SC - O(n)
*/

vector<int>v;
int i=0;
//inorder traversal to store the value in the vector
void inorder(TreeNode* root) 
{
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    //calling the inorder traversal inside this function
    BSTIterator(TreeNode* root)
    {
        i=0;
        inorder(root);
    }
    //returning the next value in the vector which stores elements of BST
    int next() 
    {
        int x=v[i];
        i++;
        return x;
}
//checks if there is a next element which means i has not reached last index yet
bool hasNext() 
{
        if(i<v.size())
        {
            return true;
        }
        return false;
}
