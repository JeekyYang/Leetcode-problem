int help(int A[],int p,int r)
{
	int i = p-1;
	int x = A[r];
	for(int j = p;j<r;j++)
	{
		if(A[j]<x)
			swap(A[++i],A[j]);
	}
	swap(A[i+1],A[r]);
	return i+1;
}
void quicksort(int A[],int p,int r)
{
	if(p<r){
		int pivot = helpe(A,p,r);
		quicksort(A,p,pivot-1);
		quicksort(A,pivot+1,q);  
	}
}
