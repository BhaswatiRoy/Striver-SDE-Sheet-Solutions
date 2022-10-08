/*
1. Steps - Using 2 stacks
   Push - Move all elements of s1 to s2
           Add x to s1
           Move all elements from s2 to s1 element by element from top of stack
   Pop - Remove from top of s1
   Peek/Top - Return top element of s1
   TC - O(n) for push, pop, O(1) for top, SC - O(n)

2. Steps - Using 2 stacks
   Push - Add elements into s1
   Pop - If s2 not empty then pop from there 
         Else move all elements from s1 to s2 element by element from top of stack then return top element of s2
   Peek/Top - If s2 not empty then return top element of s2
              Else move all elements from s1 to s2 element by element from top of stack then return top element of s2
   TC - O(1) for push and most cases of pop, O(n) for top, SC - O(n)
   
*/

stack<int>s1,s2;
void push(int x) 
{
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
} 
int pop() 
{
        int top=s1.top();
        s1.pop();
        return top;
}
int peek() 
{
        return s1.top();
}
bool empty() 
{
        if(s1.empty()==true)
        {
            return true;
        }
        return false;
}



stack<int>s1,s2;
void push(int x) 
{
        s1.push(x);
}
int pop() 
{
        int top;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        top=s2.top();
        s2.pop();
        return top;
}
int peek() 
{
        if(!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
}
bool empty() 
{
        if(s2.empty()==true && s1.empty()==true)
        {
            return true;
        }
        return false;
}
