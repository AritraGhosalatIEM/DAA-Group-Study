#include<stdio.h>
#include<stdlib.h>
 struct dnode
 {
  int data;
  struct dnode* next;
  struct dnode* prev;
 };
 
 struct dnode* head=NULL;
 struct dnode* tail=NULL;
 
 void create(int n)
 { int i;
   for(i=1;i<=n;i++)
   {  
      int x;
   	  struct dnode* newnode=(struct dnode*)malloc(sizeof(struct dnode));
	  printf("\nEnter data\n");
	  scanf("%d",&x);
	  insert_end(x);   	
   }
   
 }//void create()
 
 
 
 void insert_end(int x)
 { struct dnode* newnode=(struct dnode* )malloc(sizeof(struct dnode));
   newnode->next=NULL;
   newnode->prev=tail;
   newnode->data=x;
   
   if(head==NULL)//empty linked list
    { head=newnode;
    }
   else
   {tail->next=newnode;
   }
   tail=newnode; 	
   printf("ELEMENTS-\n");
   display();
 }//insert end
 
 
 
 void insert_front(int x)
 {
   struct dnode* newnode=(struct dnode* )malloc(sizeof(struct dnode));
   newnode->next=head;
   newnode->prev=NULL;
   newnode->data=x;
   if(head==NULL)
   	tail=newnode;
    
   else
 	head->prev=newnode;
 	
   head=newnode;
   printf("ELEMENTS-\n");
   display();
 	
 }//insert_front
 
 
 void insert_nth(int x,int n)
 {  
    if(n==1)
    {  	insert_front(x);
    	return;
	}	
    struct dnode* newnode=(struct dnode* )malloc(sizeof(struct dnode));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=x;
 	int ctr=1;
 	struct dnode* temp=head;
 	while(ctr<n-1)
 	{
 		temp=temp->next;//finding n-1 th node
 		ctr++;
	 }	 
	 if(temp->next==NULL)//last node
	  tail=newnode;
	 else
	 (temp->next)->prev=newnode;
	 
 	newnode->next=temp->next;
 	temp->next=newnode;
 	newnode->prev=temp; 	
 	printf("ELEMENTS-\n");
   display();
 }//insert at nth 
 
 
 
 
 
 
 void delete_nth(int n)
 {  
    if(n==1)
    {  	delete_front();
    	return;
	}	
    
 	int ctr=1;
 	struct dnode* temp=head;
 	while(ctr<n-1)
 	{
 		temp=temp->next;//finding n-1 th node
 		ctr++;
	 }	 
	 if((temp->next)->next==NULL)//last node
	  {delete_end();return;}
	  
	 struct dnode*temp2=temp->next;//node to be deleted
	 temp->next=temp2->next;
	 (temp2->next)->prev=temp;
	 free(temp2);
	 temp2=NULL;
	 printf("ELEMENTS-\n");
   display();
	 
 }//insert at nth 
 
 
 void delete_front()
 {
 	if(head==NULL)
 	 {
	  printf("UNDERFLOW\n");
	  return;}
	  struct dnode*temp=head;
	  if(head->next!=NULL)//readjusting links of existing nodes
	  {(head->next)->prev=NULL;
	  head=temp->next;}
	  else
	   {head=NULL;tail=NULL;}//when last node is deleted
	  free(temp);
	  temp=NULL;
	  printf("ELEMENTS-\n");
   display();	   	 
 }//delete_front
 
 
 void delete_end()
 {	
 	if(tail==NULL)
 	 {
	  printf("UNDERFLOW\n");return;
	  }
	  struct dnode* temp=tail;
	  if(temp->prev!=NULL) 
	  {
	  (temp->prev)->next=NULL;//readjusting links of existing nodes
	  tail=temp->prev;
	  }
	  else
	  {tail=NULL;head=NULL;//when last node is deleted
	  }
	  free(temp);
	  temp=NULL;  
	  printf("ELEMENTS-\n");
   display();	
 }//delete_end
 
 
 void display()
 {   struct dnode* temp=head;
 	 while(temp!=NULL)
 	 {printf("%d\t",temp->data);
 	  temp=temp->next;
	  }
	  
 }//display()
 
 
 void reverse_display()
 {struct dnode* temp=tail;
 	 while(temp!=NULL)
 	 {printf("%d\t",temp->data);
 	  temp=temp->prev;
	  }
	  
 }//reverse display()
 
 void search(int n)
 {
 	struct dnode*temp=head;
 	int ctr=1;
 	 while(temp!=NULL)
 	 { if (temp->data==n)
 	   {
	   printf("element is at %d th node",ctr);return;
	   }
 	   
 	 	ctr++;temp=temp->next;
	  }
	  printf("Element not found\n");
 	
 }
 
 int main()
 {
 	
 	int ch,n,x;
 	do
 	{ printf("\nMENU-\n1.CREATE\n2.INSERT AT END\n3.INSERT AT FRONT\n4.INSERT AT N-th POSITION\n5.DELETE FROM FRONT\n6.DELETE FROM END\n7.DELETE FROM N-th POSITION\n8.DISPLAY\n9.REVERSE DISPLAY\n10.SEARCH\n11.QUIT\nENTER CHOICE-");
 	  scanf("%d",&ch);
 	  if(ch==1)
 	   { printf("Enter the number of nodes you wish to create-\n");
 	     scanf("%d",&n);
		 create(n); 	   	
		}
	  else if(ch>=2&&ch<=4)
	   {
	   	 printf("Enter the data-\n");
	   	 scanf("%d",&x);
	   	 
	   	 if(ch==2)
	   	  insert_end(x);
	   	 else if(ch==3)
	   	  insert_front(x);
	   	 else
	   	 {printf("Enter the position-\n");
	   	 scanf("%d",&n);
	   	 insert_nth(x,n);
		 }
	   	 
	   }
	   else if(ch==5)
	    delete_front();
	   else if(ch==6)
	    delete_end();
	   else if (ch==7)
	    {printf("Enter the position-\n");
	   	 scanf("%d",&n);
	   	 delete_nth(n);
		}
 	   else if(ch==8)
 	    display();
 	   else if (ch==9)
 	    reverse_display();
 	   else if (ch==10)
 	    {printf("Enter the elemnet to be searched\n");
 	     scanf("%d",&n);
 	     search(n);
		 }
 	   else
 	    printf("EXIT---------------------"); 		
 		
 	} while(ch!=11);
 	
 	return 0;
 }
