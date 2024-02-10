#include<stdio.h>
int main()
{
	
	int a[]={1,2,3,0,4,9,0,0,5,6,9,0,0,3,5,0,0,7,6,0};
	int n=sizeof(a)/sizeof(a[0]);
	//to ensure all zeros come at the end of the array
	int i=0,j=n-1,temp;
	while(i<j)
	{
	 if(a[j]==0)//the element at end is already zero	
		j--;
	 if(a[j]!=0)//swap required
	   { 
	    if(a[i]==0)
	    {
	     temp=a[i];
	   	 a[i]=a[j];
	     a[j]=temp;
	   	 i++;
	     j++;
	    }
	    else
	     i++;//look for more zeros from front
	    
      }//if a[j]!=0
	
	}//while
	printf("Size=%d\n",n);	
	for(i=0;i<n;i++)
	 printf("%d\t",a[i]);
}
