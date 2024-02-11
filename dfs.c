#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
void dfs(unsigned int size,char name[],bool** graph,bool* visited,unsigned int current){
	visited[current]=true;
	printf("%c->",name[current]);
	for(unsigned int i=0;i<size;i++)
		if(graph[i][current] && !visited[i]){
			dfs(size,name,graph,visited,i);
		}
}
int main(){
	//input
	unsigned int N=0;
	FILE* file=fopen("graph.txt","r");
	char c;
	while((c=getc(file))!=EOF)
		if(c=='\n')N++;
	rewind(file);
	bool** graph=(bool**)malloc(sizeof(bool*)*N);
	char name[N];
	for(unsigned int i=0;i<N;i++){
		name[i]='A'+i;
		graph[i]=(bool*)calloc(N,sizeof(bool));
		for(unsigned int j=0;j<N;j++)
			if(getc(file)=='t')graph[i][j]=true;
		getc(file);//skip newline
	}
	fclose(file);
	bool* visited=(bool*)calloc(N,sizeof(bool));
	srand(time(NULL));
	unsigned int start=rand()%N;
	dfs(N,name,graph,visited,start);
	printf("END\n");
	return 0;
}
