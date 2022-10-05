/*
Find the size of list, and iterate upto (sz-n)th position from beginning
That position is the nth position from end of linked list
*/

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
        ListNode* temp=head;
        int sz=0;
        //finding size of linked list
        while(temp!=NULL)
        {
            sz++;
            temp=temp->next;
        }
        //if size and n are equal then head needs to be deleted
        if(sz==n)
        {
            return head->next;
        }
        temp=head;
        int i=(sz-n-1);
        //iterate upto nth position from end
        while(i--)
        {
            temp=temp->next;
        }
        //now delete that required node
        temp->next=temp->next->next;
        return head;
}
