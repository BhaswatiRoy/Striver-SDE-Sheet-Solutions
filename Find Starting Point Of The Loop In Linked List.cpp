/*
1. We can use a map and store the nodes into it. And traverse the map to find the common node which is loop starting point
   TC - O(n), SC - O(n)

2. We can use a fast and slow pointer and move them until we find a collision/meeting point of both.
   After that we can take another pointer and start from beginning and slow starting from collision/meeting point.
   The point at which they meet is the starting point of linked list
   TC - O(n), SC - O(1)

*/

ListNode* detectCycle(ListNode *head) 
{
        unordered_set<ListNode*>st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
            {
                return temp;
            }
            else if(st.find(temp)==st.end())
            {
                st.insert(temp);
                temp=temp->next;
            }
        }
        return NULL;
}

ListNode *detectCycle(ListNode *head) 
{
        ListNode *slow=head;
        ListNode *fast=head;   
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }   
        }
        if(fast==NULL || fast->next==NULL)
        { 
            return NULL;
        }
        while(head!=slow)
        {
            slow=slow->next;
            head=head->next;
        }
        return slow;
}
