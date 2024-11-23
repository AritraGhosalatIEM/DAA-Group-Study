#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INFINITY 69420
int** pq;
unsigned int N,pq_items,arrays;
unsigned int *index;
void _swap(unsigned int x,unsigned int y){
	int t;
	for(int i=0;i<arrays;i++){
		t=pq[i][x];
		pq[i][x]=pq[i][y];
		pq[i][y]=t;
	}
	index[pq[1][x]]=x;
	index[pq[1][x]]=y;
}
void build_heap(){
	unsigned int current,swap_index,right_child,left_child,i;
	for(i=0;i<(pq_items-1)/2;i++){
		current=i;
		do{
			left_child=2*current+1;
			right_child=2*current+2;
			swap_index=pq[0][right_child]<pq[0][left_child]?right_child:left_child;
			if(pq[0][swap_index]>=pq[0][current])
				break;
			_swap(current,swap_index);
			current=swap_index;
		}while(current<(pq_items-1)/2);
	}
	if(pq_items%2==0 && pq[0][i]>pq[0][pq_items-1])//single child node
		_swap(i,pq_items-1);
}
unsigned int bubble_up(unsigned int index,int new_val){
	pq[0][index]=new_val;
	while(index>0){
		unsigned int parent=(index-1)/2;
		if(pq[0][parent]<pq[0][index])break;
		_swap(parent,index);
		index=parent;
	}
	return index;
}
int poll(unsigned int ret){
	unsigned int swap_index=0,left_child,right_child,current=--pq_items;
	do{//bubble down
		_swap(current,swap_index);
		current=swap_index;
		left_child=2*current+1;
		right_child=2*current+2;
		swap_index=(right_child<pq_items && pq[0][right_child]<pq[0][left_child])?right_child:left_child;
	}while(swap_index<pq_items && pq[0][current]>pq[0][swap_index]);
	return pq[ret][pq_items];
}
int main(int argc,char** argv){
	//input
	N=0;
	FILE* file=fopen("graph.csv","r");
	char c;
	while((c=getc(file))!=EOF)
		if(c=='\n')N++;
	rewind(file);
	int (*graph)[N][N]=malloc(N*N*sizeof(int));
	index=malloc(N*sizeof(int));
	int* node=malloc(N*sizeof(int));
	int* distances=malloc(N*sizeof(int));
	int* parent=malloc(N*sizeof(int));
	for(unsigned int i=0;i<N;i++){
		distances[i]=INFINITY;
		parent[i]=index[i]=node[i]=i;
		for(unsigned int j=0;j<N;j++)
			fscanf(file,"%d,",&(*graph)[i][j]);
		getc(file);//skip newline
	}
	fclose(file);
	unsigned int current=argv[1][0]-'A';
	distances[index[current]]=0;
	pq={distances,nodes};
	pq_items=N;arrays=2;
	unsigned int new_dist;
	//Dijkstra
	do{
		current=poll(1);
		for(unsigned int i=0;i<N;i++)
			if(graph[current][i]!=0 && index[i]+1>=pq_items && (new_dist=distances[index[current]]+graph[current][i])<distances[index[i]])
				bubble_up(index[i],new_dist);
	}while(pq_items>0);
	return 0;
}
