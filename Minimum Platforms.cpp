/*
We can sort both arrays and check if arrival time of next train is before departure time of current train.
In that case we might require an extra station for that arriving train. 
We will also keep a count of maximum no of platforms needed at one time.
And when a train leaves we will decrease current platform count as that platform becomes empty

TC - O(nlogn), SC - O(1)
*/

int findPlatform(int arr[], int dep[], int n)
{
    	int platformcount=1,maxplatformcount=1;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	//we start with comparing arrival of 2nd train & departure of 1st train
    	int i=1,j=0;
    	while(i<n && j<n)
    	{
    	    //arrival time of next train is less or equal to departure time of one train
    	    if(arr[i]<=dep[j])
    	    {
    	        //counting current platforms occupied together
    	        platformcount++;
    	        //finding max no of platforms occupied at any momemnt of time
    	        maxplatformcount=max(platformcount,maxplatformcount);
    	        //incrementing the arrival time iterator
    	        i++;
    	    }
    	    //arrival time of next train is more than departure time of one train
    	    else if(arr[i]>dep[j])
    	    {
    	        //reducing count of 1 platform as 1 train departues before another comes
    	        platformcount--;
    	        j++;
    	    }
    	}
    	return maxplatformcount;
}
