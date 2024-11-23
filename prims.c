#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int *visited;
unsigned int node_count,u;
void visit(int node){
	for(unsigned int i=node_count;i>=u;i--)visited[i+1]=visited[i];//shift greater elements to right
	visited[u-1]=node;
	node_count++;
}
bool unvisited(int node){
	unsigned int m,l,current;
	u=node_count-1,l=0;
	while(u>l){
		m=(u+l)/2;
		current=visited[m];
		if(current==node)return false;
		else if(node>current)l=m+1;
		else u=m-1;
	}
	return true;
}
int main(){
	unsigned int N=0;
	FILE* file=fopen("graph.csv","r");
	char c;
	while((c=getc(file))!=EOF)
		if(c=='\n')N++;
	rewind(file);
	int graph[N][N];
	int mst[N][N];
	for(unsigned int i=0;i<N;i++){
		for(unsigned int j=0;j<N;j++){
			fscanf(file,"%d,",&graph[i][j]);
			mst[i][j]=0;
		}
		getc(file);//skip newline
	}
	fclose(file);
	visited=(int*)malloc(sizeof(int)*(N));
	node_count=0;u=1;
	unsigned int min,from,min_node,node=rand()%N;
	visit(node);
	do{
		min=-1;
		for(unsigned int i=0;i<node_count;i++){//visited nodes
			node=visited[i];
			for(unsigned int j=0;j<N;j++)//connections of visited nodes
				if(graph[node][j]>0 && graph[node][j]<min && unvisited(j)){
					min=graph[node][j];
					from=node;
					min_node=j;
				}
		}
		mst[from][min_node]=mst[min_node][from]=min;
		visit(min_node);
	}while(node_count!=N);//works for fully connected graphs only
	for(unsigned int i=0;i<N;i++){
		for(unsigned int j=0;j<N;j++)
			printf("%d,",mst[i][j]);
		printf("\n");
	}
	return 0;
}
