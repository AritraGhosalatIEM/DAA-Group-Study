#include<stdio.h>
#include<stdlib.h>

int *a;//global pointer always pointing at first element of array
int n;//size of array
int curr_n;//number of elements currently stored in array

void create( )
{   if(curr_n>n)
   {printf("EXCEEDED MAX SIZE\n");
    return;
   }
    a=(int*)malloc(n*sizeof(int));
   
    
	int i;
	printf("\nENTER ELEMENTS\n");
	for(i=0;i<curr_n;i++)
	{scanf("%d",&a[i]);
	}
	 display();
}

void insert(int pos,int x)
{
	if(curr_n==n)
	{printf("ARRAY FULL\n");
	 return;	
	}
	if(pos<1||pos>curr_n)
	 {printf("INVALID INDEX\n");
	  return;
	 }
	
	int index=pos-1;//index to be inserted at
	int i;
	
	for(i=curr_n;i>index;i--)
	{a[i]=a[i-1];
	 }
	 
	 a[index]=x;
	 curr_n++;
	 display();	 
	
}


void delete(int pos)
{
	if(pos<1||pos>curr_n)
	 {printf("INVALID INDEX\n");
	  return;
	 }
	int i,index=pos-1;
	for(i=index;i<curr_n-1;i++)
	 a[i]=a[i+1];
	
	curr_n--;
	display();
	
}


int search(int x)
{
	int flag=0;
	int i;
	for(i=0;i<curr_n;i++)
	{ if(a[i]==x)
	   return i;	   
    }
   return -1;
}


void max_min( )
{	
  int max=a[0];
  int min=a[0];
  int i;
  for(i=1;i<curr_n;i++)
  { if(a[i]>max)
      max=a[i];
    if(a[i]<min)
      min=a[i];
  } 	
  printf("MAX ELEMENT=%d\n",max);
  printf("MIN ELEMENT=%d\n",min);
  	
}


void display( )
{	printf("ELEMENTS-\n");
    int i; 
	for(i=0;i<curr_n;i++)
	 printf("%d\t",a[i]);
    printf("\n"); 
}



int main()
{
	int p,x;
	printf("Enter max array size\n");
	scanf("%d",&n);
	printf("Enter current size\n");
	scanf("%d",&curr_n);
	create();
	
	
	int ch;
	
	do
	{printf("MENU-\n1.Insert\n2.Delete\n3.Search\n4.Find Max and Min\n5.Display\n6.QUIT\nEnter choice");
	
	scanf("%d",&ch);
	
	if(ch==1)
	 {
	  printf("Enter position\n");
	  scanf("%d",&p);
	  printf("Enter value\n");
	  scanf("%d",&x);
	  insert(p,x);
	 }
	 else if(ch==2)
	 {
	  printf("Enter position\n");
	  scanf("%d",&p);
	  delete(p);
	 }
	 else if(ch==3)
	 {printf("Enter element to be searched\n");
	  scanf("%d",&x);
	  int i=search(x);
	  if(i==-1)
	   printf("ELEMENT NOT FOUND\n");
	  else
	   printf("ELEMENT FOUND AT INDEX-%d\n",i);	 	
	 }
	 else if(ch==4)
     { 
       max_min();
	 
	 }	 
	 else if(ch==5)
	 {
	 	display();
	 }
	 else
	  printf("EXIT-----------------------\n");
    }while(ch!=6);	
	
}
