/*
1. Storing all values in a vector and sorting them and again adding them to a new linked list
   TC - O(n*m), SC - O(n*m)
   
2. Recursively merge 2 linked lists from end and then merge 3rd last linked list with merged one. Continue this until we come to 1st linked list
   While merging we have to keep it in sorted order so we will compare the data of nodes before adding to merged list
*/

Node *flatten(Node *root)
{
    Node* curr1=root;
    Node* curr2=root;
    vector<int> v;
    while(curr1)
    {
      while(curr2)
      {
          v.push_back(curr2->data);
          curr2=curr2->bottom;
      }
      curr2=curr1->next;
      curr1=curr1->next;
    }
    sort(v.begin(),v.end());
    Node *ans=new Node(-1);
    Node *newhead=ans;
    for(auto it:v)
    {
        Node *temp=new Node(it);
        ans->bottom=temp;
        ans=ans->bottom;
    }
    return newhead->bottom;
}


Node *merge(Node *a, Node *b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    Node *res;
    //if a is smaller then res=a and recursively call for others in linked list a
    if(a->data<b->data)
    {
        res=a;
        res->bottom=merge(a->bottom,b);
    }
    //if b is smaller then res=a and recursively call for others in linked list b
    else
    {
        res=b;
        res->bottom=merge(a,b->bottom);
    }
    //finally point next of result as NULL and return it
    res->next=NULL;
    return res;
}

Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    {
        return root;
    }
    //recursively call until we reach to last linked list and hit base case when root->next is NULL
    //this will help to merge from end and return merged linked list from back
    return merge(root,flatten(root->next));
}
