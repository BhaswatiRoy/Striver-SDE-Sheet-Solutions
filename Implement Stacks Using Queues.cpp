/*
1. Steps - Take 2 queues q1,q2
   Push - Add x to q2
           Move all elements from q1 to q2 element by element from front of q1
           Swap all elements of q1 & q2
   Pop  - Remove from front of q1

2. Steps - Take 2 queues q1,q2
   Push - Add x to q
          Iterate till q.size()-1 elements and remove them fron front and add to back
   Pop - Remove from front of q
*/

queue<int>q1,q2;
MyStack() 
{
        
}
void push(int x) 
{
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
}
int pop() 
{
        int top = q1.front();
        q1.pop();
        return top;
}
int top() 
{
        return q1.front();
}
bool empty() 
{
        if(q1.empty()==true)
        {
            return true;
        }
        return false;
}


queue<int>q;
MyStack() 
{
        
}
void push(int x) 
{
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
}
int pop() 
{
        int top = q.front();
        q.pop();
        return top;
}
int top() 
{
        return q.front();
}
bool empty() 
{
        if(q.empty()==true)
        {
            return true;
        }
        return false;
}
