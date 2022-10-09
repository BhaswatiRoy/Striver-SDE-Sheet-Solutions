/*
1. By traversing to every node, we can check if that node is a BST or not,if yes then it can be counted in a BST.
   Basicaly, pass every node to validate BST function.
   Then we can pass that node into another function to count nodes in the bst/ count sum of values inside nodes
   TC - O(n^2), SC - O(1)
   
2. One more way is to check that for every node the highest value in left subtree < node value & lowest value in right subtree > node value
   Then only all nodes in left subtree are smaller than the node and all nodes in right subtree are greater than the node - that node has valid bst below it.
   We will keep 4 variables to check for each node ~
      a. bst - stores 1/0 whether it is part of bst or not
      b. size/sum - stores size/sum of bst if any
      c. min - min value in right subtree
      d. max - max value in left subtree
   If for any node both left and right subtrees form bst then the node can form bst. Now we will check min < node && max > node.
   If any node is not forming bst we pass 0 in bst, min, max parameter
   TC - O(n), SC - O(1)
*/

vector<int> bst(Node* root)
{
        //for nodes having either of right/left children - only 1 child
        //the other node is the null node so for them max - INT_MAX, min - INT_MIN
        //because then node value > min(INT_MIN) & node value < max(INT_MAX)
        if(root==NULL)
        {
            return {1,0,INT_MAX,INT_MIN};
        }
        //for leaf nodes max & min both are the node value itself
        if(root->left==NULL && root->right==NULL)
        {
            return {1,1,root->data,root->data};
        }
        //for every node a checking of left and right data will be done
        vector<int>left=bst(root->left);
        vector<int>right=bst(root->right);
        //if left and right both are bsts then there is possibility that the node can also be bst
        if(left[0]==1 && right[0]==1)
        {
            //node val > max of left subtree, node val < min of right subtree
            if(root->data>left[3] && root->data<right[2])
            {
                int x=left[2];
                int y=right[3];
                //if x or y are INT_MAX, INT_MIN then they are null nodes
                //so they will be replaced by node value now
                if(x==INT_MAX)
                {
                    x=root->data;
                }
                if(y==INT_MIN)
                {
                    y=root->data;
                }
                //left size + right size + 1 is new size as +1 is for node/root
                return {1,left[1]+right[1]+1,x,y};
            }
        }
        //if bst condition not fulfilled then we will return max bst size between left & right
        //all other values are 0 
        return {0,max(left[1],right[1]),0,0};
}
int largestBst(Node* root)
{
        //vector to store {bst,size,max,min} 
        //bst - whether that node forms bst, size - size of bst if formed
        //min - min value of right subtree, max - max value of left subtree
    	vector<int>ans=bst(root);
    	return ans[1];
}
