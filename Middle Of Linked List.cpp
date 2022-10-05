/*
Keeping 2 pointers - fast & slow, fast moves by 2 steps, slow moves by 1 step
This way when fast reaches to end, slow reaches to middle point
*/

ListNode* middleNode(ListNode* head) 
{
        ListNode* fast=head;
        ListNode* slow=head;
        //fast moves 2 places and slow moves 1 place
        //this way as fast reaches to end of list slow reaches to middle of list
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
}
