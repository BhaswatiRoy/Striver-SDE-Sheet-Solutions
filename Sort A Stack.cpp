/*
We will recursively solve this problem to sort the stack. 
We can bring out all elements of stack until we reach to last element and once done we can now place elements in their correct position.
If the stack is empty we can insert without any issue. But if not then we will again recursively pop elements and put the current element x in correct position.

TC - O(n), SC - O(1)
*/

void insertcorrpos(int x, stack<int>&s)
{
    //if stack is empty or x > st.top then we can insert without issue
    if(s.size()==0 || s.top()<x)
    {
        s.push(x);
    }
    //otherwise we have to recursively keep popping
    //until we reach a state where stack is empty or x > st.top
    else
    {
        int a=s.top();
        s.pop();
        //once elements are inserted at correct position 
        insertcorrpos(x,s);
        //we can now push the elements we popped into the stack
        s.push(a);
    }
}
void reverse(stack<int>&s)
{
    if(s.size()>0)
    {
        //bring out elements until last element is reached 
        int x=s.top();
        s.pop();
        reverse(s);
        //once all reverse recursion calls are over and last element is reached
        //we will start inserting elements in their correct positions
        insertcorrpos(x,s);
    }
}
void SortedStack :: sort()
{
    reverse(s);
}
