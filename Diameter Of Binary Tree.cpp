/*
diameter - longest path between nodes. It doesn't neccessarily need to pass through root
If we can find the left height and right height for every given node we can find the length of maximum path passing through that node
*/

int maxpath=0;
int findheight(TreeNode *root)
{
        if(root==NULL)
        {
            return 0;
        }
        //finding left and right heights of any node recursively
        int lefth=findheight(root->left);
        int righth=findheight(root->right);
        
        //with end of this function the maxpath variable will store the maximum path length/diameter
        maxpath=max(maxpath,(lefth+righth));
        
        //returns maximum height of each node
        return 1+max(lefth,righth);
}
int diameterOfBinaryTree(TreeNode* root) 
{
        if(root==NULL)
        {
            return 0;
        }
        findheight(root);
        
        return maxpath;
}
