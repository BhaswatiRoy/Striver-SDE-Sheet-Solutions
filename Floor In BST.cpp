/*
Floor of key - largest value present <= key
If we get value equal to key then that is itself floor value
If we get values smaller than k then traverse to right in hope of getting a larger value
If we get values larger than k then traverse to left in hope of getting a smaller value than k

TC - O(N), SC - O(1)
*/

int floorbst(TreeNode* root, int key)
{
     int floor=-1;
     while(root!=NULL)
     {
       //if value equal to key is found return that value itself
       if(root->val==key)
       {
         floor=root->val;
         return floor;
       }
       else if(root->val<k)
       {
         floor=root->val;
         root=root->right;
       }
       else if(root->val>k)
       {
         root=root->left;
       }
     }
     return floor;
}
