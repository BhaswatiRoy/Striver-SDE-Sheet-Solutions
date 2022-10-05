/*
use a map to store all node values and for each node values check if (k-nodeval) is present or not in the map in traversal itself

TC - O(n), SC - O(n)
*/

unordered_map<int,int>mp;
bool twosum(TreeNode* root, int k)
{
        if(root==NULL)
        {
            return false;
        }
        //if the (target-nodeval) is found in the map then the sum exists
        if(mp.find(k-root->val)!=mp.end())
        {
            return true;
        }
        //add the nodeval everytime to the map with every traversal
        mp[root->val]++;
        
        //return a true if any of left/right traversals return true
        return twosum(root->left,k) || twosum(root->right,k);
}
bool findTarget(TreeNode* root, int k) 
{
        bool ans=twosum(root,k);
        return ans;
}
