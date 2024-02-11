#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void first(int memory[],unsigned int blocks,unsigned int required){
	for(unsigned int i=0;i<blocks;i++)
		if(memory[i]>=required){
			memory[i]-=required;
			printf("%d from block %d.\n",required,i);
			return;
		}
	printf("Cannot get %d.\n",required);
}
void best(int memory[],unsigned int blocks,unsigned int required){
	int from=-1;unsigned int diff=-1;
	for(unsigned int i=0;i<blocks;i++)
		if(memory[i]>=required && (memory[i]-required)<diff){
			diff=memory[i]-required;
			from=i;
		}
	if(from==-1)printf("Cannot get %d.\n",required);
	else{
		memory[i]=diff;
		printf("%d from block %d.\n",required,i);
	}
}
void worst(int memory[],unsigned int blocks,unsigned int required){
	int from=-1;unsigned int diff=0;
	for(unsigned int i=0;i<blocks;i++)
		if(memory[i]>=required && (memory[i]-required)>diff){
			diff=memory[i]-required;
			from=i;
		}
	if(from==-1)printf("Cannot get %d.\n",required);
	else{
		memory[i]=diff;
		printf("%d from block %d.\n",required,i);
	}
}
int main(int argc,char** argv){
	unsigned int mems=1;
	for(int i=0;argv[1][i]!='\0';i++)
		if(argv[1][i]==',')mems++;
	unsigned int available[mems];
	available[0]=atoi(strtok(argv[1],","));
	for(int i=1;i<mems;i++)
		available[i]=atoi(strtok(NULL,","));
	char* token=strtok(argv[2],",");
	void (*algo)(int[],unsigned int,unsigned int);
	switch(argv[3][0]){
		case 'f':
			algo=&first;
			break;
		case 'b':
			algo=&best;
			break;
		case 'w':
			algo=&worst;
			break;
		default:
			printf("Not a valid algorithm.\n");
			return 1;
	}
	while(token!=NULL){
		(*algo)(available,mems,atoi(token));
		token=strtok(NULL,",");
	}
	return 0;
}
