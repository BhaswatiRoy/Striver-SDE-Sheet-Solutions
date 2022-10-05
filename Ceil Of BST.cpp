/*
Ceil of key - smallest value present >= key
If we get value equal to key then that is itself ceil value 
If we get values smaller than k then traverse to right in hope of getting a larger value
If we get values larger than k then traverse to left in hope of getting a smaller value than k

TC - O(N), SC - O(1)
*/

int ceilbst(TreeNode* root, int key)
{
     int ceil=-1;
     while(root!=NULL)
     {
       if(root->data==key)
       {
         ceil=root->data;
         return ceil;
       }
       else if(root->data<key)
       {
         root=root->right;
       }
       else if(root->data>key)
       {
         ceil=root->data;
         root=root->left;
       }
     }
     return ceil;
}
