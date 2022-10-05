/*
Taking 2 pointers - fast & slow, fast moves 2 steps and slow moves 1 step
If fast and slow meet at any point then there is a cycle in linked list

TC - O(n), SC - O(1)
*/

bool hasCycle(ListNode *head) 
{
        if(head==NULL)
        {
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
}
