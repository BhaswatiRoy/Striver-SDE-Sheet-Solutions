/*
A celebrity is a person who is known to all but does not know anyone at a party. M[i][i] = 1 means person i knows person j

1. We can make 2 vectors - in[i] where we can store how many people knows i & out[i] where we can store how many people i knows
   Now if there is any person where in[i] = n & out[i] = 0 then he is a celebrity. Thus we can traverse through the grid and store it
   TC - O(n^2), SC - O(n)
   
2. Assuming initially person 0 is celebrity and check if person 0 knows person 1 keep going upto n. If person 0 knows person 1 then person 0 can't be celebrity.
   But in that case person 1 probably can be celebrity. This way we can continue and in end again loop and check if our assumption was true or not.
   TC - O(N), SC - O(1)
*/

int celebrity(vector<vector<int> >& M, int n) 
{
        vector<int>in(n,0);
        vector<int>out(n,0);
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M.size();j++)
            {
                //M[i][i] = 1 means person i knows person j
                if(M[i][j]==1)
                {
                    in[j]++;
                    out[i]++;
                }
            }
        }
        //if there is any person where in[i] = n-1 & out[i] = 0 then he is a celebrity
        for(int k=0;k<n;k++)
        {
            //n-1 is done as the person knowing themselves is not taken to count
            if(in[k]==n-1 && out[k]==0)
            {
                return k;
            }
        }
        return -1;
}


int celebrity(vector<vector<int>>& M, int n) 
{
        //initially celebrity is assumed to be 0 index person
        int c=0;
        for(int i=0;i<n;i++)
        {
            //if c knows i index person then c can't be celebrity 
            if(M[c][i]==1)
            {
                //thus there are chances that i index person can be celebrity
                c=i;
            }
        }
        //now to make sure that final value of c is actually celebrity or not
        for(int j=0;j<n;j++)
        {
            //i should not be c as we can't compare any person to itself
            //now if there is a case that c knows someone or someone doesn't knows c then c is not celebrity
            if(j!=c && (M[c][j]==1 || M[j][c]==0))
            {
                return -1;
            }
        }
        return c;
}
