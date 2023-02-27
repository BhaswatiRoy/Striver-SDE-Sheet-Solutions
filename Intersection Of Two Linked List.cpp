/*
1. We can use a map and store the nodes into it. And traverse the map to find the common node which is intersection point
   TC - O(n), SC - O(n)
   
2. We can use 2 pointers - temp1, temp2. If any pointer is not null keep traversing, otherwise set it to head of opposite list. 
   Keep traversing till we find the intersection point
   TC - O(n), SC - O(1)
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        unordered_map<ListNode*,int>mp;
        while(temp1!=NULL)
        {
            mp[temp1]++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            if(mp.find(temp2)!=mp.end())
            {
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
            }
            //if 1st pointer is not null then travrse 
            if(temp1!=NULL)
            {
                temp1=temp1->next;
            }
            //otherwise set it to head and traverse from beginning 
            else
            {
                temp1=headA;
            }
            //if 1st pointer is not null then travrse 
            if(temp2!=NULL)
            {
                temp2=temp2->next;
            }
            //otherwise set it to head and traverse from beginning 
            else
            {
                temp2=headB;
            }
        }
        return NULL;
}
