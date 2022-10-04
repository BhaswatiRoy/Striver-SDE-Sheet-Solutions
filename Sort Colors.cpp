/*
Keep a count of all colors 0,1,2 then clear the array and add them again in order
While adding we will add 0's first then 1's and finally 2's
*/

void sortColors(vector<int>& nums) 
{
        //0=red, 1=white, 2=blue
        int cr=0,cw=0,cb=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cr++;
            }
            else if(nums[i]==1)
            {
                cw++;
            }
            else if(nums[i]==2)
            {
                cb++;
            }
        }
        nums.clear();
        //adding red balls
        while(cr>0)
        {
            nums.push_back(0);
            cr--;
        }
        //adding white balls
        while(cw>0)
        {
            nums.push_back(1);
            cw--;
        }
        while(cb>0)
        {
            nums.push_back(2);
            cb--;
        }
}
