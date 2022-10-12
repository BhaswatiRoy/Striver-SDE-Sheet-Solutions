/*
We can increase value of given nodes as many times as possible to convert given BT to sum tree. 
We will start from root and go to down and if - left + right children < root val - replace the children val with root val
Else replace root val with children sum val.

        40                   40                      150
     /      \            /        \              /        \
    10       20    ->   40         40   ->     80         70
   /  \     /  \      /    \                  /  \       /  \
  2    5   30   40   40     40               40   40    30   40

TC - O(n), SC - O(1)
*/

void changetree(TreeNode *root)
{
  if(root==NULL)
  {
    return;
  }
  int child=0;
  //if left exists then add to child value
  if(root->left!=NULL)
  {
    child+=(root->left->data);
  }
  //if right exists then add to child value
  if(root->right!=NULL)
  {
    child+=(root->right->data);
  }
  //if children sum value is more than root then replace root value by children sum value
  if(child>=root->data)
  {
    root->data=child;
  }
  //otherwise replace children values by root value
  else
  {
    if(root->left!=NULL)
    {
      root->left->data=root->data;
    }
    if(root->right!=NULL)
    {
      root->right->data=root->data;
    }
    
    //traverse for both left and right subtrees
    changetree(root->left);
    changetree(root->right);
    
    //in end when we come back we assign the left + right children sum to root so that it becomes a sum tree
    //update only for non leaf nodes
    int total=0;
    if(root->left!=NULL)
    {
      total+=(root->left->data);
    }
    if(root->right!=NULL)
    {
      total+=(root->right->data);
    }
    if(root->left!=NULL || root->right!=NULL)
    {
      root->data=total;
    }
    
