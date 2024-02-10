#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int stack[100];
int top=-1;

void push(int x)
{
	if(top==99)
	 {
	  printf("OVERFLOW\n");
      return ;
     }  
     
     top=top+1;
     stack[top]=x;
     
}
int pop()
{
	if(top==-1)
	 printf("UNDERFLOW\n");
	else
	 {
	 int a=stack[top];
	 top--;
	 return a;
     }
	
}


int evaluate(int a,int b,char c)
{
	if(c=='+')
	 return a+b;
    
	if(c=='-')
	 return a-b;
	
	if(c=='/')
	 return a/b;
    
	if(c=='*')
	 return a*b;
	
	if(c=='^')
	 return pow(a,b);
    
	return 0;
	
}


int main()
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
	  if(isdigit(c))
	    push(c-'0');
	  else
	  { int val2=pop();
	    int val1=pop();
	    push(evaluate(val1,val2,c));		
	 }
		  
   }//for
	
	int ans=stack[top];
	printf("FINAL ANSWER=%d\n",ans);	
	
}//main()
