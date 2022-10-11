/*
1st element of preorder traversal is root of tree. 
All elements to left of root in inorder traversal is part of left subtree. All elements to right of root in inorder traversal is part of right subtree

Inorder - [40,20,50,10,60,30], Preorder - [10,20,40,50,30,60] - thus we can recursively find inorder & preorder for all subtrees until we are left with 1 node
 
          10
    /            \
 inorder       inorder
-[40,20,50]   -[60,30]
 preorder      preorder
-[20,40,50]   -[30,60]
    20           30
 /       \      /
40       50    60

TC - O(n), SC - O(1)
*/

//prestart & preend = start and end indices of preorder which we put values recursively
//instart & inend = start and end indices of inorder which we put values recursively
Node* constructtree(int pre[], int prestart, int preend, int in[], int instart, int inend, unordered_map<int,int>&mp)
{
        //if we don't have any preorders left we can stop
        if(prestart>preend || instart>inend)
        {
            return NULL;
        }
        //creating the root with prestart index from preorder traversal
        Node *root=new Node(pre[prestart]);
        //find index of the current root from inorder traversal using map
        int indexroot=mp[root->data];
        //all elements to left are (indexroot - instart) elements
        int numsleft=indexroot-instart;
        
        //new preorder for left subtree starts from prestart+1 and goes upto numsleft elements
        //new inorder for left subtree starts from instart and goes upto indexroot-1 elements
        root->left=constructtree(pre, prestart+1, prestart+numsleft, in, instart, indexroot-1, mp);
        //new preorder for right subtree starts from prestart+numsleft+1 and goes upto preend
        //new inorder for right subtree starts from indexroot+1 and goes upto inend
        root->right=constructtree(pre, prestart+numsleft+1, preend, in, indexroot+1, inend, mp);
        
        return root;
}
Node* buildTree(int in[],int pre[], int n)
{
        unordered_map<int,int>mp;
        //since all inorder elements are unique so we can hash them with their index 
        //this will help us to easily find the index of node in inorder traversal
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        Node *root=constructtree(pre, 0, n-1, in, 0, n-1, mp);
        return root;
}
