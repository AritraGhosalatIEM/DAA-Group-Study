//linked list implementation
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
 
 struct node
 {
  int data;
  struct node* next; 	
 };
 
 struct node* head=NULL;
 int is_odd=1;//assuming odd number of nodes
 //insert front
 void insert_front(int x)
 { 
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->next=NULL;
 
 if (head!=NULL)
    { temp->next=head;//putting next of temp as the current head node
    }
 head=temp;//updating head
 }
 
 //insert end
 void insert_end(int x)
 {struct node* temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;

  
  if(head==NULL)//empty list
   {head=temp;
     return ;
	 }  
	 
  struct node* temp2=head;
  while(temp2->next!=NULL)//finding out the last node
  {temp2=temp2->next;
  }
  
  temp2->next=temp;
 }
 
 //insert n
 void insert_n(int x,int n)
 { struct node* temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   temp->next=NULL;
   
   if(n==1)
   {temp->next=head;
    head=temp;
    return;
   }
    int ctr;
    struct node* temp2 = head;
    for(ctr=1;ctr<n-1;ctr++)
    {temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;    
 }
 
 //delete front
 void delete_front()
 {
 	if(head==NULL)
 	  {printf("LIST EMPTY ALREADY");
 	   return;
	   }
	struct node* temp=head;
	head=head->next;
	free(temp);
	temp=NULL; 
	   
 }
 
 //delete end
 void delete_end()
 { struct node* temp=head;
   while(temp->next->next!=NULL)//finding second last node
   {temp=temp->next;
   }
   struct node* temp2=temp->next;
   temp->next=NULL;
   free(temp2);
   temp2=NULL;
 }
 
 //delete n
 void delete_n(int n)
 {
  struct node* temp=head;
  if(n==1)
  { head=temp->next;
    free(temp);
    return;
  }
  int ctr;
  for(ctr=1;ctr<n-1;ctr++)
  {temp=temp->next;
  }
  struct node* temp2=temp->next;//nth node
  temp->next=(temp->next)->next;
  free(temp2);
  
 }
 
 //traverse
 void traverse()
 { struct node* temp2=head;
  while(temp2!=NULL)//finding out the last node
  {printf("%d\t",temp2->data);
    temp2=temp2->next;
  }
  printf("\n");
 }
 
  struct node* reverse(struct node* h)//generalised function for reversal
 {
   struct node*current,*prev,*next;
    prev=NULL;
    current=h;
	while(current!=NULL)
	 { next=current->next;
	   current->next=prev;
	   prev=current;
	   current=next;
	 } 
	return prev;	 	
 }
 
 void middle()
 {   if(head==NULL)
	 printf("SLL is empty"); 
 	struct node*fptr=head;
	struct node*sptr=head;
 	
 	while(1)
 	{   	         
 		if(fptr->next==NULL)//last node reached in case of odd number of nodes
 		 {printf("check for odd\n");
		  printf("ONE middle element-%d\n",sptr->data);
		   break;
	    }
 		else if((fptr->next)->next==NULL)//second last node reached in case of even number of nodes
         {printf("check for even\n");
		  printf("TWO middle elements due to even number of nodes. 1st middle element-%d and second middle element-%d\n",sptr->data,(sptr->next)->data); 		
 	     break;
		 }
		 
		sptr=sptr->next;
		fptr=fptr->next->next;
	 }	
 	
 }//middle
 struct node* first_middle()
 {
 	struct node*fptr=head;
	struct node*sptr=head;
	while(fptr->next!=NULL &&fptr->next->next!=NULL)
      { sptr=sptr->next;
        fptr=fptr->next->next;
      }
    if(fptr->next!=NULL)
    is_odd=0;
    
    return sptr;
 	
 }
 
 int is_palindrome()
 {
 	struct node*mid=first_middle();
 	if(is_odd==0&&(mid->data!=mid->next->data))//even then check for mid values here only
 	 {
	  return 0;}
    
    mid->next=reverse(mid->next);
    traverse();
 	struct node*temp1=head;
 	struct node*temp2=mid->next;
 	while(temp2!=NULL)//this check is only vaid for odd nodes
 	 {
 	 	if(temp1->data!=temp2->data)
 	 	 return 0;
 	 	 
 	 	temp1=temp1->next;
 	 	temp2=temp2->next;
	  }
 	return 1;
 	
 }
  
 bool hasCycle(struct node *head) {
    struct node*sptr,*fptr;
    sptr=head;
    fptr=head;
    while(fptr!=NULL&&fptr->next!=NULL)
     {  sptr=sptr->next;
        fptr=fptr->next->next;

        if(sptr==fptr)
         return true;
     }
     return false;
    
}
struct node *detectCycle(struct ListNode *head) {
    struct node* fptr,*sptr;
    sptr=head;
    fptr=head;
    while(fptr!=NULL&&fptr->next!=NULL)
     {
         sptr=sptr->next;
         fptr=fptr->next->next;

         if(sptr==fptr)
         {
            sptr=head;
            while(sptr!=fptr)
            {
             sptr=sptr->next;
             fptr=fptr->next;
            }
            return sptr;
         }
     }
     return NULL;
}


 int main()
 {  
 	insert_n(24,1);
 	insert_n(25,2);
 	insert_n(26,3);
 	insert_n(27,4);
 	insert_n(26,5);
 	insert_n(25,6);
 	insert_n(24,7);
 	insert_n(28,8);
 	
 	traverse();
 	printf("%d\n",is_palindrome());
 	//head->next=reverse(head->next);
 	//traverse();
 		
     int cycle=0;
  	
 }
