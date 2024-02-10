#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

char stack[100];
int top=-1;

void push(char x)
{
	if(top==99)
	 {
	  printf("OVERFLOW\n");
      return ;
     }  
     
     top=top+1;
     stack[top]=x;
     
}
void pop()
{
	if(top==-1)
	 printf("UNDERFLOW\n");
	else
	 top--;
	
}



int compatible(char c1,char c2)
{	
	if(  (c1=='(' && c2==')')  ||  (c1=='{' && c2=='}')  ||  (c1=='[' && c2==']')  )
	 return 1;
	else
	 return 0;	
}


void parenthesis_balanced()
{	
	char exp[100];
	printf("Enter expression-\n");
	scanf("%s",&exp);
	int n=0;
	int i;
	for(i=0;exp[i]!='\0';i++)
	 n++;	 
	 
	printf("Expression= %s\n",exp);
	printf("length=%d\n",n);
	
	//scanning expression
	for(i=0;i<n;i++)
	{
	  char c=exp[i];
	 if(c=='('||c=='{'||c=='[')//opening
	  push(c);
	  
	 if(c==')'||c=='}'||c==']')//closing
	  { if((top==-1)||(compatible(stack[top],c)==0))//empty list or non pairing
	     {
		 printf("UNBALANCED\n");
		 return ;
	     }
	    else
	     pop();  
	  	
	  }//closing
	 
	 }//for
	 
	 
	 if(top==-1)
	 {
	  printf("BALANCED");
	  
	 }
	 else
	 printf("UNBALANCED");
	 
}//parenthesis balanced


int main()
{
	 parenthesis_balanced()	;
	 	
	 	
	 	
	 }
	 
	 
	 
	 





