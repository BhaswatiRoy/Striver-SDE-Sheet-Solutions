/*
Move the slow pointer to middle and reverse the part after middle of linked list
Now increment slow by 1 and take it to position after middle
Now keep comparing from 1st and middle if any node values are different then not palindrome

TC - O(n), SC - O(1)
*/

bool isPalindrome(ListNode* head) 
{
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        //fast pointer moves to end & slow pointer moves to middle 
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the part after slow pointer of linked list i.e reverse the part after middle of linked list
        ListNode*prev=NULL,*curr=slow->next,*temp;
        while(curr!=NULL)
        {                                 
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;
        //traverse to right half
        slow=slow->next;
        //now check left and right halves of middle end 
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
}
