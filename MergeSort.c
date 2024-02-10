#include<stdio.h>
int count=0;
int main()

{   	
	int i, n;
	printf("enter the number of elements \n");
	scanf("%d",&n);
	
	int a[n];
	printf("enter elements.....\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("Entered array- \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
	printf("\nInversion Pairs \n");
	int c=MergeSort(a,0,n-1);
	printf("\nNumber of Inversion pairs-%d \n",count);
	printf("Sorted array- \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
	
}//main()

void MergeSort(int *a, int start, int end)
{
	
	if(start<end)
	{
		int mid=(start+end)/2;
		MergeSort(a,start,mid);
		MergeSort(a,mid+1,end);
		
		Merge(a,start,end);
	}			
	
}

void Merge(int *a,int start, int end)
{   
	int startc=start;
	
	int mid=(start+end)/2;
	int l1=mid-start+1;
	int l2=end-mid;
	int a1[l1];
	int a2[l2];
	int i,j,k,midc=mid+1;
	//copying to first array
	for(i=0;i<l1;i++)
	{a1[i]=a[startc++];
	}
	//copying to second array
	for(i=0;i<l2;i++)
	{a2[i]=a[midc++];
	}
	
	i=0;
	j=0;
	k=start;
	while(i<l1&&j<l2)
	{
		if(a1[i]<a2[j])
		 {a[k++]=a1[i++];
		 }
		else if(a1[i]>a2[j])//inversion pairs will exist
		{
		int m;
		for( m=i;m<l1;m++)
		 {
		  printf("(%d , %d)\n",a1[m],a2[j]);
		  count++; 
        }
		 a[k++]=a2[j++];
		}
		else
		{a[k++]=a1[i++];
		  j++;
		}
	 }
	while(i<l1)
	   a[k++]=a1[i++];
	while(j<l2)
	   a[k++]=a2[j++];
	return count;
}//Merge

