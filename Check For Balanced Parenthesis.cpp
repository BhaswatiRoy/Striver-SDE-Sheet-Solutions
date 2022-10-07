/*
Using a stack we can check for balanced parenthesis. Everytime we get an open bracket we put it inside stack and for a close bracket we pop a matching open bracket.
This way in end if the stack is empty it means that all open brackets have matching closed brackets. Otherwise not

TC - O(n) SC - O(n)
*/

bool isValid(string s) 
{
        int n=s.length();
        stack<char>st;
        if(!s.empty())
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                {
                    st.push(s[i]);
                }
                else if(!st.empty())
                {
                    
                if(s[i]==')' && st.top()=='(')
                {
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{')
                {
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='[')
                {
                    st.pop();
                }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        //bool val=true;
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        //return val;
}
