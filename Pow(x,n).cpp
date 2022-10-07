/*
Just using recursion and maths concepts

TC - O(logn), SC - O(1)
*/

double myPow(double x, int n) 
{
        if(n==0)
        {
            return 1;
        }
        if(n<0) 
        { 
            n=abs(n);
            x/=x;
        }
        if(n%2==0)
        {
            return myPow(x*x,n/2);
        
        }
        else
        {
            return x*myPow(x*x,n/2);
        }
}
