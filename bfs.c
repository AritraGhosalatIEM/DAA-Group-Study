#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
typedef struct node{
	unsigned int data;
	struct node* after;
} Node;
Node *head,*tail;
void init_queue(){
	head=(Node*)malloc(sizeof(Node));
	tail=head;
}
bool empty(){return head==tail;}
void enqueue(int value){
	tail->data=value;
	Node* new=(Node*)malloc(sizeof(Node));
	tail->after=new;
	tail=new;
}
unsigned int dequeue(){
	Node* remove=head;
	unsigned int ret=remove->data;
	head=remove->after;
	free(remove);
	return ret;
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
	init_queue();
	bool* visited=(bool*)calloc(N,sizeof(bool));
	bool* queued=(bool*)calloc(N,sizeof(bool));
	srand(time(NULL));
	unsigned int current=rand()%N;//random start
	enqueue(current);
	//BFS
	do{
		current=dequeue();
		visited[current]=true;
		printf("%c->",name[current]);
		for(unsigned int i=0;i<N;i++)
			if(graph[i][current] && !visited[i] && !queued[i]){
				enqueue(i);
				queued[i]=true;
			}
	}while(!empty());
	printf("END\n");
	return 0;
}
