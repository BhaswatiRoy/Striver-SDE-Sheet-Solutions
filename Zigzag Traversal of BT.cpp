/*
While doing level order traversal keep a track of which level it is whether it's an even level or odd level and do reversals of the level nodes accordingly

TC - O(n), SC - O(n)
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
        vector<vector<int>>ans;
        bool bval=false;
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
            }
            if(bval==false)
            {
                bval=true;
            }
            else if(bval==true)
            {
                reverse(v.begin(),v.end());
                bval=false;
            }
            ans.push_back(v);
        }
        return ans;
}
