/*
1. Create a complete new linked list and keep two pointers list1 & list2 to add smaller nodes to get final list in sorted manner
   TC - O(n), SC - O(n)
   
2. Do inplace using 2 pointers list1 & list2 by changing links
   TC - O(n), SC - O(1)
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
        //new list created
        ListNode *dummy,*temp;
        dummy = new ListNode();
        temp = dummy;
        while(list1!=NULL && list2!=NULL)
        {
            //add smaller of both node values into newlist
            if(list1->val<list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;   
            }
            temp=temp->next;
        }
        //check if we missed reaching to end of any of the lists
        if(list1!=NULL)
        {
            temp->next=list1;
        }
        if(list2!=NULL) 
        {
            temp->next=list2;
        }
        return dummy->next;
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
        //list1 will always be at smaller node value
        //if any of the list is null then return other
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        //if list1 is not pointing to smaller node then swap them 
        if(list1->val>list2->val)
        {
            swap(list1,list2);
        }
        //assigning head of merged sorted list is pointing at smaller list - list1
        ListNode *result=list1;
        while(list1!=NULL && list2!=NULL)
        {
            //at every iteration assign a temp pointer to point o last proper node
            ListNode *temp=NULL;
            //iterate upto when list1 will have larger value than list2 
            while(list1!=NULL && list1->val<=list2->val)
            {
                //then set temp to last proper node
                temp=list1;
                list1=list1->next;
            }
            //when the iteration ends means at a point list2->val < list1->val
            temp->next=list2;
            //then swap them
            swap(list1,list2);
        }
        return result;
}
