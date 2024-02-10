#include <stdio.h>

int count_occur(int a[], int start, int end,int key) 
{ 
     if (start == end)//single element 
	{
        if(a[start]==key)
        return 1;
    } 
	if(end>=start)//not found and low high equal
	{	
	 return 0;	
	}	
   
    int mid = (start + end) / 2;
    return count_occur(a, start, mid,key)+ count_occur(a, mid + 1, end,key);
   
}

int main() 
{   
    printf("Enter no of elements -\n");
    int n;
    scanf("%d",&n);
    int a[n],i;
    
    printf("Enter data-\n");
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     
    printf("Enter key value-\n");
    int x;
    scanf("%d",&x);
    printf("key %d is found %d number of times",x,count_occur(a,0,n-1,x));
	    
}
