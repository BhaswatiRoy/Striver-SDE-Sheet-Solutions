/*
Mid element of a sorted array is the root of BST. If array given is not sorted make sure to sort it
Left parts of BST will be part of left subtree, and right parts of BST will be part of right subtree
This way we can keep constructing the BST

TC - O(n), SC - O(1)
*/

TreeNode* constructbst(int left, int right, vector<int>&nums)
{
        //if left is more than right then base case is hit
        if(left>right)
        {
            return NULL;
        }
        //middle of the array will be root node 
        int mid=(left+right)/2;
        TreeNode* currnode=new TreeNode(nums[mid]);
        
        //left part of mid will consist of left subtree for the root element at mid index
        currnode->left=constructbst(left,mid-1,nums);
        
        //right part of mid will consist of right subtree for the root element at mid index
        currnode->right=constructbst(mid+1,right,nums);
        
        //return the created tree in the end
        return currnode;
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
        int n=nums.size();
        TreeNode* root=constructbst(0,n-1,nums);
        return root;
}
