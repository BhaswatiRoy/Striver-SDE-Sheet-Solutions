/*
1. For every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value - Sum Tree
   For every node we can check if left and right subtrees follow sum tree property or not.
   Since we are using a different function for finding sum which in worst case will again traverse n nodes so n^2 complexity
   TC - O(n^2), SC - O(1)
   
2. If we can combine both functions then we can reduce complexity.
   TC - O(n), SC - O(1)
*/

int sum(Node *root)
{
        if(root==NULL)
        {
            return 0;
        }
        int left=sum(root->left);
        int right=sum(root->right);
        //sum of any tree is left sum + right sum + root val
        return left+right+root->data;
}
bool isSumTree(Node* root)
{
        //if the root is null or we have reached leaf nodes then return
        //since leaf nodes don't have any children so can't take them into consideration
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return true;
        }
        //find left sum for left subtree
        int left=sum(root->left);
        //find right sum for right subtree
        int right=sum(root->right);
        
        //if for given node left and right subtree values equal to root value
        //also left and right subtrees must return true too
        if(left+right==root->data && isSumTree(root->left)==true && isSumTree(root->right)==true)
        {
            return true;
        }
        return false;
}


int sumtree=1;
int check(Node* root)
{
        if(root!=NULL)
        {
            return 0;
        }
        //on reaching to leaf node we return
        if(root->left!=NULL && root->right!=NULL)
        {
            return root->data;
        }
        //if at any point it is found not to be sum tree then return 0
        if(sumtree==0)
        {
            return 0;
        }
        int left=check(root->left);
        int right=check(root->right);
        //if at any point sum tree property is not followed then set the variable as 0
        if(left+right!=root->data)
        {
            sumtree=0;
        }
        //in end return sum of the subtree
        return left+right+root->data;
    }
    bool isSumTree(Node* root)
    {
        check(root);
        if(sumtree==1)
        {
            return true;
        }
        return false;
}
