/*
Boundary is - Root + Left Boundary Excluding Leaves + Leaves + Right Boundary Excluding Leaves in Reverse Order
Thus we traversed and stored the nodes in the given order respectively
TC - O(n), SC - O(n) {Left & Right Boundaries will take O(H) and normal traversal will take O(n)}
*/
bool isleaf(Node* root)
{
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        return false;
}
void addleftboundary(Node *root, vector<int>&result)
{
        Node* curr=root->left;
        while(curr!=NULL)
        {
            if(isleaf(curr)==false)
            {
                result.push_back(curr->data);
            }
            if(curr->left!=NULL)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
}
void addrightboundary(Node *root, vector<int>&result)
{
        Node* curr=root->right;
        vector<int>temp;
        while(curr!=NULL)
        {
            if(isleaf(curr)==false)
            {
                temp.push_back(curr->data);
            }
            if(curr->right!=NULL)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            result.push_back(temp[i]);
        }
}
void addleaves(Node *root, vector<int>&result)
{
        if(isleaf(root)==true)
        {
            result.push_back(root->data);
            return;
        }
        if(root->left!=NULL)
        {
            addleaves(root->left,result);
        }
        if(root->right!=NULL)
        {
            addleaves(root->right,result);
        }
}
vector <int> boundary(Node *root)
{
        vector<int>result;
        if(root==NULL)
        {
            return result;
        }
        //if root node is not leaf then we can add them to result
        if(isleaf(root)==false)
        {
            result.push_back(root->data);
        }
        addleftboundary(root,result);
        addleaves(root,result);
        addrightboundary(root,result);
        return result;
}
