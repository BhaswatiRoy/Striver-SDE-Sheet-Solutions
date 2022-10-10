/*
The numbers are given in reversed format of linked list - l1 = [2,4,3], l2 = [5,6,4] , ans = [7,0,8]

We can start traversing from beginning and keep two variables sum and carry to calculate the sum and keep count of carry
If suppose we get sum as 12 then we will keep 12 % 10 = 2 in the node and keep 12 / 10 = 1 in the carry

TC - O(n), SC - O(n)
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        //dummy keeps pointing to head of new list while temp traverses and adds new nodes
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        int sum=0,carry=0;
        //we will stop traversing until both linked list becomes null as well carry becomes 0
        //because if carry is not 0 then we have to add carry to end
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            sum=0;
            //add value from l1 linked list if not null
            if(l1!=NULL)
            {
                sum+=(l1->val);
                l1=l1->next;
            }
            //add value from l2 linked list if not null
            if(l2!=NULL)
            {
                sum+=(l2->val);
                l2=l2->next;
            }
            //add the carry to the sum
            sum+=carry;
            //if suppose sum is 11 then we will put 11%10 = 1 into node and put 11/10 = 1 into carry
            carry=sum/10;
            ListNode *newnode= new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
}
