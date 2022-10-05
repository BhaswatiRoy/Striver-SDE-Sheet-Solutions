/*
Keep 3 pointers curr, prevl, nextl 
Set nextl to next node of temp, and set temp's link to previous node of temp
Increement prevl to temp and temp to nextl

TC - O(n), SC - O(1)
*/

ListNode* reverseList(ListNode* head) 
{
        ListNode* temp=head;
        ListNode* prevl=NULL; //link to previous node
        ListNode* nextl=NULL; //link to next node
        while(temp!=NULL)
        {
            nextl=temp->next;
            temp->next=prevl;
            prevl=temp;
            temp=nextl;
        }
        head=prevl;
        return head;
}
