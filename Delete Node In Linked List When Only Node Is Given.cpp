/*
We are replacing the current node value with next node value 
And then setting current node link to next's next link
Since head reference is not given so we can't traverse and actually delete the node
As we are only given the node reference so we deleted the value not node
*/

void deleteNode(ListNode* node) 
{
        int nextval=node->next->val;
        node->val=nextval;
        node->next=node->next->next;
}
