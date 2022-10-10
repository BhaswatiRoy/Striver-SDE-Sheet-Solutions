/*
Inversions - two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

We can do this using merge sort. While merging elements into 1 single array we can count the inversions too
        5 3 2 4 1                  1 2 3 4 5
       /         \                /         \
    5 3 2        4 1           2 3 5        1 4
   /     \      /   \          /    \       /  \
  5 3     2    4     1       3 5     2      1   4
 /   \                      /   \
5     3                    3     5

When merge sort breaks down elements then while merging we will see if a[i] > a[j] i = left subtree, j = right subtree - then we will count them.
Like for a[i] = 2 3 5 & a[j] = 1 4 we have 2 > 1 so we also have (2,1), (3,1), (5,1) since all subarrays are in sorted form in merge sort
which is why we do count += (mid-i) to count total inversions. Thus here i = 0, mid = 3 thus count = (3-0) = 3

TC - O(nlogn), SC - O(n)
*/

long long int merge(long long arr[], long long temp[], int left, int mid, int right)
{
        int i,j,k;
        long long int inversions=0;
        //i=index for left subarray, j=index for right subarray, k=index for merged subarray
        i=left;
        j=mid;
        k=left;
        while(i<=mid-1 && j<=right)
        {
            //if left element is smaller than right element then we will add the smaller element
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            //otherwise we will add the smaller element and also increase inversions count
            //suppose 5,3,2 & 1 is to be merged then we have (mid-i) = 3 inversions for (5,1),(3,1),(2,1)
            //since while merging all smaller arrays are sorted so we can count inversions without traversing
            else
            {
                temp[k++]=arr[j++];
                //diff = count of occurences to left of mid = inversion counts
                inversions+=(mid-i);
            }
        }
        //add remaining elements if any from 1st part
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        //add remaining elements if any from 2nd part
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        //add all elements from temporary array to main array
        for(int k=left;k<=right;k++)
        {
            arr[k]=temp[k];
        }
        return inversions;
}
    
long long int mergesort(long long arr[], long long temp[], int left, int right)
{
        int mid;
        long long int countinversions=0;
        if(left<right)
        {
            mid=(left+right)/2;
            //left call 
            countinversions+=mergesort(arr,temp,left,mid);
            //right call
            countinversions+=mergesort(arr,temp,mid+1,right);
            
            //after both recursion calls comes the merging part
            countinversions+=merge(arr,temp,left,mid+1,right);
        }
        return countinversions;
}
    
long long int inversionCount(long long arr[], long long N)
{
        //temp array created for using in merge sort so that actual array is not modified
        long long temp[N];
        for(int i=0;i<N;i++)
        {
            temp[i]=arr[i];
        }
        int left=0, right=N-1;
        return mergesort(arr,temp,left,right);
}
