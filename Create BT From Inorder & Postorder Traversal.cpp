/*
Last element of postorder traversal is root of tree.
All elements to left of root in inorder traversal is part of left subtree. All elements to right of root in inorder traversal is part of right subtree.

Inorder - [40,20,50,10,60,30], Postorder - [40 50 20 60 30 10] - thus we can recursively find inorder & postorder for all subtrees until we are left with 1 node.

          10
    /            \
 inorder       inorder
-[40,20,50]   -[60,30]
 postorder      postorder
-[40,50,20]   -[60,30]
    20           30
 /       \      /
40       50    60

TC - O(n), SC - O(n)
*/


//poststart & postend = start and end indices of postorder which we put values recursively
//instart & inend = start and end indices of inorder which we put values recursively
TreeNode* constructtree(vector<int>& inorder, int instart, int inend, vector<int>&postorder, int poststart, int postend, unordered_map<int,int>&mp)
{
        //if we don't have any postorders left we can stop
        if(instart>inend || poststart>postend)
        {
            return NULL;
        }
        //creating the root with poststart index from postorder traversal
        TreeNode* root=new TreeNode(postorder[postend]);
        //find index of the current root from inorder traversal using map
        int indexroot=mp[root->val];
        //all elements to left are (indexroot - instart) elements
        int numsleft=indexroot-instart;
        
        //new postorder for left subtree starts from poststart and goes upto numsleft-1 
        //new inorder for left subtree starts from instart and goes upto indexroot-1 
        root->left=constructtree(inorder,instart,indexroot-1,postorder,poststart,poststart+numsleft-1,mp);
        //new postorder for right subtree starts from postorder and goes upto postend-1 
        //new inorder for right subtree starts from indexroot+1 and goes upto inend
        root->right=constructtree(inorder,indexroot+1,inend,postorder,poststart+numsleft,postend-1,mp);
        
        return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
        int n=inorder.size();
        if(inorder.size()!=postorder.size())
        {
            return NULL;
        }
        unordered_map<int,int>mp;
        //since all inorder elements are unique so we can hash them with their index 
        //this will help us to easily find the index of node in inorder traversal
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=constructtree(inorder,0,n-1,postorder,0,n-1,mp);
        return root;
}
