#include<stdio.h>
#include<stdlib.h>
#define INFINITY 69420
void path(unsigned int start,unsigned int end,unsigned int N,int (*table)[N][N],int (*next)[N][N]){
	printf("%c - %c :",'A'+start,'A'+end);
	if((*table)[start][end]==INFINITY){
		printf("No path.\n");
		return;
	}
	unsigned int at;
	for(at=start;at!=end;at=(*next)[at][end]){
		if(at==-1){
			printf("Negative cycle.\n");
			return;
		}
		printf("%c->",'A'+at);
	}
	if((*next)[at][end]==-1){
		printf("Negative cycle.\n");
		return;
	}
	printf("%c\n",'A'+end);
}
int main(){
	unsigned int N=0;
	FILE* file=fopen("graph.csv","r");
	char c;
	while((c=getc(file))!=EOF)
		if(c=='\n')N++;
	rewind(file);
	int (*table)[N][N]=malloc(N*N*sizeof(int));
	int (*next)[N][N]=malloc(N*N*sizeof(int));
	unsigned int val;
	for(unsigned int i=0;i<N;i++){
		for(unsigned int j=0;j<N;j++){
			fscanf(file,"%d,",&val);
			if(val!=0){
				(*table)[i][j]=val;
				(*next)[i][j]=j;
			}
			else
				(*next)[i][j]=(*table)[i][j]=INFINITY;
		}
		getc(file);//skip newline
	}
	fclose(file);
	for(unsigned int node=0;node<N;node++)
		for(unsigned int row=0;row<N;row++)
			for(unsigned int column=0;column<N;column++)
				if((val=(*table)[row][node]+(*table)[node][column])<(*table)[row][column]){//better path
					(*table)[row][column]=val;
					(*next)[row][column]=(*next)[row][node];
				}
	for(unsigned int node=0;node<N;node++)//detect negative cyclec
		for(unsigned int row=0;row<N;row++)
			for(unsigned int column=0;column<N;column++)
				if((val=(*table)[row][node]+(*table)[node][column])<(*table)[row][column]){//better path
					(*table)[row][column]=-INFINITY;
					(*next)[row][column]=-1;
				}
	for(unsigned int start=0;start<N;start++){//display all paths
		for(unsigned int end=0;end<start;end++)
			path(start,end,N,table,next);
		for(unsigned int end=start+1;end<N;end++)
			path(start,end,N,table,next);
	}
	return 0;
}
