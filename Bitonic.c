#include<stdio.h>
 #include<stdlib.h>
 int main()
 {
 int n;
 do{
 printf("enter length\n");
 scanf("%d",&n);
 if(n==2)
  printf("Enter atleast 3 elements\n");
  
  }while(n==2);
  //while
  
  
 int* a=(int*)malloc(n*4);
 
 printf("enter elements-\n");
 int i;
 
 //input array
 for(i=0;i<n;i++)
  {scanf("%d",&a[i]);}
  
  //search for bitonic
  printf("Bitonic-\n");
 for(i=1;i<n-1;i++)
 {
    if((a[i]>a[i-1]&& a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
     printf("%d ",a[i]);
  
 }
}//main
