#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{    
    if (r >= l)
	 {         
        int mid = l + (r - l) / 2;         
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x);
        else
		    return binarySearch(arr, mid + 1, r, x);
     }
    return -1;
}

int main()
{
    int n;
   printf("Enter the length of array\n");
    scanf("%d",&n);
   int* a=(int*)malloc(n*4);
    printf("Enter elements in ascending order:\n");
   int i=0,x,j,flag=0;
   for(;i<n;i++)
  {
   scanf("%d",&a[i]);
  }

  printf("Enter search value-\n");
  scanf("%d",&x); 
    int index = binarySearch(a, 0, n - 1, x);
 
    if (index == -1) 
        printf("Element not found");
    else 
        printf("Element is present at index-%d", index);
 
}//main()
