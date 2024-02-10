#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
struct queue
{ int array[MAX];
  int front,rear,size;	
};


struct queue* q1;

struct queue* q2;

void allocate(struct queue* q)
{
	q->front=-1;
	q->rear=-1;
	q->size=0;
	
}

void enqueue(struct queue* q,int x)
{  
   if((q->rear+1)%MAX==q->front)
     {printf("OVERFLOW\n");
      return;
	 }
	 
   if(q->front==-1)
     q->front++;
   
   q->rear=(q->rear+1)%MAX;//linear:q->rear++
   q->array[q->rear]=x;
   q->size++;	
}

void dequeue(struct queue*q)
{  
  if(q->front==-1)
   {printf("Underflow\n");
    return;
   }
   
   if(q->front==q->rear)//single element
	{q->front=q->rear==-1;
	 q->size=0;
	 return;
	}
	
   q->front=(q->front+1)%MAX;	
   q->size--;
	
}

void display(struct queue* q)
{   printf("\n");
int i;
	for(i=q->front;i<=q->rear;i++)
	{printf("%d\t",q->array[i]);
	}
}




int main()
{   
    q1 = (struct queue*)malloc(sizeof(struct queue));
    q2 = (struct queue*)malloc(sizeof(struct queue));

  allocate(q1);
  allocate(q2);


	enqueue(q1,100);
	enqueue(q1,101);
	enqueue(q1,102);
	enqueue(q1,103);
	enqueue(q1,104);
	enqueue(q1,105);
	
	
	display(q1);
	
	dequeue(q1);
	dequeue(q1);
	
	display(q1);
	
	enqueue(q2,200);
	enqueue(q2,201);
	enqueue(q2,202);
	enqueue(q2,203);
	enqueue(q2,204);
	enqueue(q2,205);
	
	
	display(q2);
	
	dequeue(q2);
	dequeue(q2);
	
	display(q2);
}
