/*
We need to merge both nums1 & nums2 array into nums1 array itself, m = nums1.size(), n = nums2.size() - nums1 has n 0's in end
We will merge them from behind and in end also put extra elements remaining in nums2 which weren't added
Like nums1 = [ ], nums2 = [ 2 ] , the 1st while loop will not run so the 2nd while loop will do the work

TC - O(n+m), SC - O(1)
*/

void merge(vector<int>&nums1, int m, vector<int>&nums2, int n) 
{
        //k is index where both arrays size ends
        int k=n+m-1,i=m-1,j=n-1;
        //we are starting from backwards of nums1 so that we don't lose elements in front
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
}
