/*
Designing a stack that supports push, pop, top, and retrieving the minimum element in constant time i.e O(1) time complexity for each function.
This can be done using 2 stacks individually

TC - O(1), SC - O(n)
*/

//store all elements randomly - normal stack 
stack<int>st1;
//store elements such that min element lies in top - min stack
stack<int>st2;
MinStack() 
{
        
}
    
void push(int val) 
{
        st1.push(val);
        //store element in min stackif that element is smaller or equal to top element of min stack
        if(st2.empty() || st2.top()>=val)
        {
            st2.push(val);
        }
}
    
void pop() 
{
        //pop the min stack element only if that element is also popped from actual stack
        if(st1.top()==st2.top())
        {
            st2.pop();
        }
        st1.pop();
}
    
int top() 
{
        //return top element of normal stack
        return st1.top();
}
    
int getMin() 
{
        //return top element of min stack
        return st2.top();
}
