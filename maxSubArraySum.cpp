int maxSubArraySum(int A[],int n)
{
	if(0 == n) return 0;
	int thissum = A[0];
	int maxsum = A[0];
	for(int i=1;i<n;i++)
	{
		if(thissum <= 0 )
			thissum = A[i];
		else
			thissum += A[i];
		maxsum = max(thissum,maxsum);
	}
	return maxsum;
}
//test the push function
