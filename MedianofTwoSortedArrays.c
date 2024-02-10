#include<stdio.h>
#include<stdlib.h>

double Median(int* a, int n1, int* b, int n2)
 {
    // if a is larger we conduct search on b:
    if (n1 > n2) return Median(b, n2, a, n1);
    int n = n1 + n2; 
    int left = (n1 + n2 + 1) / 2; // length of left half of virtual sorted array
    // apply binary search on smaller array 
    
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) /2;//how many to take from first array to form left half of virtually combined array
        int mid2 = left - mid1;//how many remaining to take froms second array to complete left half of virtually combined array
        
        // calculate l1, l2, r1, and r2;
        int left1 = INT_MIN, left2 = INT_MIN,right1 = INT_MAX, right2 = INT_MAX;
        
        //ensuring no index out of bounce
        if (mid1 < n1)
		  right1 = a[mid1];
        if (mid2 < n2)
		  right2 = b[mid2];
        if (mid1 - 1 >= 0)
		  left1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) 
		 left2 = b[mid2 - 1];

        if (left1 <= right2 && left2 <= right1)//point of symmetry in virtually combiend array located
		 {
			if (n % 2 !=0) //odd number of elements
			{
			    if (left1 > left2)
			        return (double)left1;
			    else
			        return (double)left2;
			} 
			else {//even number of elements
			    if (left1 > left2)
			        return ((double)left1 + (double)(right1 < right2 ? right1 : right2)) / 2.0;
			    else
			        return ((double)left2 + (double)(right1 < right2 ? right1 : right2)) / 2.0;
                }
        }
        
        else if (left1 > right2) 
		 high = mid1 - 1;
        else 
		 low = mid1 + 1;
    }
    return 0; 
}

int main()
 {   int n1,n2;
	 printf("enter the size of first array-\n");
	 scanf("%d",&n1);
	 printf("enter the size of second array-\n");
	 scanf("%d",&n2);
	 
	 int *a=(int*)malloc(n1*sizeof(int));
	 int *b=(int*)malloc(n2*sizeof(int));
	 int i,j;
	 
	 printf("enter first array-\n");
	 for(i=0;i<n1;i++)
	  scanf("%d",&a[i]);  
	 printf("enter second array-\n");
	 for(i=0;i<n2;i++)
	  scanf("%d",&b[i]);
	  
	  printf("\nMedian-%f",Median(a,n1,b,n2)); 	
}
