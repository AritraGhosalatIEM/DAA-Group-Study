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

int preced(char c)
{
	if(c=='+'||c=='-')
	 return 1;
	if(c=='*'||c=='/')
	 return 2;
	if(c=='^')
	 return 0;
	return -99;
	
}

int main()
{
	char exp[100];
	char result[100];
	int k=0;
	printf("Enter expression-\n");
	scanf("%s",&exp);
	int n=0;
	int i;
	for(i=0;exp[i]!='\0';i++)
	 n++;	 
	 
	printf("Expression= %s\n",exp);
	printf("length=%d\n",n);
	
	for(i=0;i<n;i++)
	{
	  char c=exp[i];
	  
	  if( isdigit(c) || isalpha(c) ) //operand
	   printf("%c",c);
	   
	   
	  else if(c=='(')//opening parenthesis
	   push(c);
	   
	   
	  else if(c==')')//closing parenthesis
	  {
	  	while(stack[top]!='(')
	  	{printf("%c",stack[top]);
	  	 pop();
		  }
		pop();//remove the  (	
	   }
	   
	   
	   else//operator
	   { 
	     if(c=='^'&&stack[top]=='^')//right associativity rule
	      push(c);
	      
	     else
	      {
		  while( top!=-1 && stack[top]!='(' && preced(stack[top]) >= preced(c) )
	      { printf("%c",stack[top]);
	        pop();
		  }
		  push(c);
	     }//pushing current op
   	   }
    
	}//for
	
	while(top!=-1)
	 {      printf("%c",stack[top]);
	        pop();
	    }	
		
}
