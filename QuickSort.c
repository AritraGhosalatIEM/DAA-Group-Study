#include <stdio.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int divide(int arr[], int s, int e)
{
	int pivot = arr[e];
	int i = (s - 1);
    int j;
	for (j = s ; j <e; j++)
	 {
		if (arr[j] <= pivot) 
		{
			i++;
			swap(&arr[i], &arr[j]);//placing elements less tha pivot
		}
	}
	i++;
	swap(&arr[i], &arr[e]); //placing the pivot 
	return i;
}
void QuickSort(int arr[], int s, int e)
{
	if (s < e) 
	{	int pi = divide(arr, s, e);
		QuickSort(arr, s, pi - 1);
		QuickSort(arr, pi + 1, e);           
	}
}

int main()
{   int i, n;
	printf("enter the number of elements \n");
	scanf("%d",&n);
	
	int a[n];
	printf("enter elements.. \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("Entered array before sorting- \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
	
	QuickSort(a, 0, n-1);
	
	printf("\nEntered array after sorting- \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
}//main
