#include<stdio.h> 
#include<stdlib.h> 
      struct bnode  
     {  
          int data;  
          struct bnode *left, *right;  
      }  ;
      
      struct bnode *root=NULL;  
     
     
struct bnode* queue[100];
int front=-1;
int rear=-1;


struct bnode * create()  
{     int choice;
   printf("Press 1 to create new node and 0 to exit ");  
   scanf("%d", &choice); 
     
   if(choice==0)   
    return 0;  
  
  else  
 { int data;  
   struct bnode *temp= (struct bnode*)malloc(sizeof(struct bnode)); 
   
   printf("Enter data-");  //for the current node
   scanf("%d", &data);  
   temp->data = data;  
   printf("FOR LEFT CHILD OF %d........", data);  
   temp->left = create();  
   printf("FOR RIGHT CHILD OF %d........", data);    
   temp->right = create();  
   return temp;   
 }  

} //create 


void enqueue(struct bnode*ptr)
{   if(rear==99)
    {printf("OVERFLOW");
     return;
    }
	if(front==-1)//first element
	{front=0;
	 }
	rear=rear+1;
	queue[rear]=ptr;
	
}

void dequeue()
{ 
	if(front==-1)//empty queue
	{printf("UNDERFLOW\n");
	return;
	 }
	if(front==rear)//single element
	{front=rear=-1;
	}
	else
	 front=front+1;	
}//dequeue

void insert_level_order(int x)
{
    struct bnode *newnode = (struct bnode *)malloc(sizeof(struct bnode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = x;

    if (root == NULL) {
        root = newnode;
        return;
    }

    enqueue(root);

    while (front != -1) {
        struct bnode *temp = queue[front];
        dequeue();

        if (temp->left == NULL) {
            temp->left = newnode;
            break;  // Break out of the loop after insertion
        } else
            enqueue(temp->left);

        if (temp->right == NULL) {
            temp->right = newnode;
            break;  // Break out of the loop after insertion
        } else
            enqueue(temp->right);
    }
    front=rear=-1;//EXTREMELY IMPORTANT AND NECESSARY STEP OR ELSE IF WE USE SAME QUEUE FOR THE LEVEL ORDER TRAVERSAL IT WILL NOT WORK ON EMPTY QUEUE
}



int search(struct bnode* node, int value)
{   
    if(node==NULL)
	 return 0;
	 
	if(node->data==value)
	 return 1;
	
	if (search(node->left,value)==1)
	 return 1;
	else
	 return search(node->right,value);
	
}

void delete(int key)
{
	 if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
           root= NULL;
        else
            return;
    }
    struct bnode* key_node = NULL;
    struct bnode* temp;
    struct bnode* last;
    enqueue(root);
   
    while (front!=-1) 
	{
        temp = queue[front];
        dequeue();
        if (temp->data == key)
            key_node = temp;
        if (temp->left) {
            last = temp; 
            enqueue(temp->left);
        }
        if (temp->right) {
            last = temp; 
            enqueue(temp->right);
        }
    }//while
    if (key_node != NULL) 
	{
        key_node->data
            = temp->data; 
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        free(temp);
    }
    
front=-1;rear=-1;	
}//delete


void level_order(struct bnode* r)
{
	if(r==NULL)
	 {printf("EMPTY TREE\n");
	  return;
	 }
	enqueue(r);
	
	while(front!=-1)//queue not empty
	{ struct bnode* current=queue[front];
	  printf("%d\t",current->data);
	  if(current->left!=NULL)
	    enqueue(current->left);
	  if(current->right!=NULL)
	   enqueue(current->right);
	  dequeue();
	}
	front=-1;rear=-1;
}//level order


void preorder_traversal(struct bnode* node)//root left right
{ 
 if(node==NULL)
   return;
  printf("%d\t",node->data);//the root
  preorder_traversal(node->left);//the left node
  preorder_traversal(node->right);//the right node	
}



void postorder_traversal(struct bnode* node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);    
    printf("%d\t", node->data);
}



void inorder_traversal(struct bnode* node)
{
	if(node==NULL)
   return;
  
  preorder_traversal(node->left);//the left node
  printf("%d\t",node->data);//the root
  preorder_traversal(node->right);//the right node
	
}


 void main()  
    {  
        //root = create(); 
        insert_level_order(1);        
        insert_level_order(2);
        insert_level_order(3);        
        insert_level_order(4);
        insert_level_order(5);
        insert_level_order(6);
        insert_level_order(7);
        
        
		printf("PREORDER-\n");
		preorder_traversal(root);
		
		printf("\nPOSTORDER-\n");
		postorder_traversal(root);
		
		printf("\nINORDER-\n");
		inorder_traversal(root); 
		
		printf("\nLEVEL ORDER-\n");
		level_order(root); 
		
		delete(5);
		printf("\nLEVEL ORDER-\n");
		level_order(root); 
		delete(4);
		printf("\nLEVEL ORDER-\n");
		level_order(root); 
		
		printf("\n%d",search(root,60));
		
    }  //main()
