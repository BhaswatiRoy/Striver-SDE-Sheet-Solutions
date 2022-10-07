/*
By doing any traversal we can swap the left and right children

TC - O(n), SC - O(1)
*/

void mirror(Node* node) 
{
        if(node==NULL)
        {
            return;
        }
        //swapping both left and right nodes
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
}
