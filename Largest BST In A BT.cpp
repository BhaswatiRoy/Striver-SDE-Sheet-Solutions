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
   If for any node both left and right subtrees form bst then the node can form bst. Now we will check min < node && max > node
   TC - O(n), SC - O(1)
*/

