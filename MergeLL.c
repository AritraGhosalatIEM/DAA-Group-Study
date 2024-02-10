//merging two sorted linked lsits
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

 struct node
 {
   int data;
   struct node* next; 	
 };
 struct node* head1=NULL;
 struct node*head2=NULL;
 struct node*head3=NULL;
 

struct node* create(struct node* head)//creates the linkedlist and returns its head pointer
 {  struct node*temp;
    int n;
    printf("Enter the number of nodes-\n");
    scanf("%d",&n);
    int data;
    printf("Enter data-\n");
    int i;
    for(i=1;i<=n;i++)
    {  
      //creating the newnode
	   scanf("%d",&data);
	   struct node*newnode=(struct node*)malloc(sizeof(struct node));
	   newnode->data=data;
	   newnode->next=NULL;
	   
	  //adding the newnode to the existing linked lists's end
	  if(i==1)//the first node
        {head=newnode;
         temp=head;
		}
	  else
	   {temp->next=newnode;
	   temp=temp->next;
	   }    	    	
	}
	
	return head;
 }
 
 void traverse(struct node* head)
 { struct node*temp=head;
 
  while(temp!=NULL)
  {printf("%d\t",temp->data);
   temp=temp->next;
  }
 	printf("\n"); 	
 }
 
 void merge1( )//without extra space
 {
 	if(head1==NULL)
 	 {
	 head3=head2;
 	 return;}
 	if(head2==NULL)
 	 {
	  head3=head1;
	  return;}
 	
 	if(head1==NULL&&head2==NULL)
 	 {
	  printf("BOTH LISTS EMPTY\n");
	  return;}
 	
 	struct node* p=head1;
 	struct node* q=head2;
 	struct node* s;
 	
 	if(p->data<q->data)
 	 {s=p;
 	  p=p->next; 	  
	 }
	 
	 else if(q->data<p->data)
	 {
	  s=q;
	  q=q->next;
	 }
	 
 	head3=s;//initialising the new sorted ll node
 	
 	while(p!=NULL&&q!=NULL)
 	{ 		
 		if(p->data<q->data)
 	   {s->next=p;
 	    s=s->next;
 	    p=p->next; 	  
	   }
	 
	   else if(q->data<p->data)
	   {
	    s->next=q;
	    s=s->next;
	    q=q->next;
	   }
 		else//both data equal
 	   { s->next=p;
 	     p=p->next;
	     s=s->next;
	     s->next=q;
	     q=q->next;
	     s=s->next;
	    } 		
	 }//while
	 //remaining link
	 if(p!=NULL)
	  s->next=p;
	else if(q!=NULL)
 	 s->next=q;
}//merge1()
 
 void merge2( )//with extra space
 { 	struct node* temp1=head1;
 	struct node* temp2=head2;
 	struct node* temp3;
 	int di;
 	
 	while(temp1!=NULL&&temp2!=NULL)
 	{ if(temp1->data<temp2->data)
 	       { di=temp1->data;
 	         temp1=temp1->next;
			}
	  else if(temp2->data<temp1->data)
	  { di=temp2->data;	    
	    temp2=temp2->next;
	  }
	  	  
	  else
	  { di=temp2->data;	     
	    temp1=temp1->next;
	    temp2=temp2->next;
	  }
	  
	  struct node*newnode=(struct node*)malloc(sizeof(struct node));
	  newnode->next=NULL;
	  newnode->data=di;
	  
	  if(head3==NULL)
	  {head3=newnode;
	   temp3=head3;
	  }
	  else
	   {temp3->next=newnode;
	    temp3=temp3->next;}
	    
	 }//whuile
 	 	
 	if(temp2!=NULL)
 	 {
	  temp3->next=temp2;
	   }
 	else if(temp1!=NULL)
 	 {
	  temp3->next=temp1;
	}
 
  }//merge2
 int main()
 {
 	printf("FOR FIRST LINKED LIST\n");
 	head1=create(head1);
 	printf("FOR SECOND LINKED LIST\n");
 	head2=create(head2);
 	
	 traverse(head1);
	 traverse(head2);
	 printf("SORTED LL");
	 merge1();
	 traverse(head3);
	   	
 }
