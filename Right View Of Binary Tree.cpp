/*
Traverse recursively in preorder traversal - Root, Right, Left
And everytime we reach to a level for 1st time we store the value
And since we are traversing right first in recursive way so we get right view

TC - O(n), SC - O(n)
*/

void rightside(Node *root,int level,vector<int>&ans)
{
        if(root==NULL)
        {
            return;
        }
        if(level==ans.size())
        {
            ans.push_back(root->data);
        }
        rightside(root->right,level+1,ans);
        rightside(root->left,level+1,ans);
    }
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        rightside(root,0,ans);
        return ans;
}
