/*
Traverse recursively in preorder traversal - Root, Left, Right
And everytime we reach to a level for 1st time we store the value
And since we are traversing left first in recursive way so we get left view

TC - O(n), SC - O(n)
*/

void leftside(Node *root,int level,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    leftside(root->left,level+1,ans);
    leftside(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
    vector<int>ans;
    leftside(root,0,ans);
    return ans;
}
