#include<stdlib.h>
unsigned int *sets;
void initialize(unsigned int N){
	sets=(unsigned int)malloc(sizeof(int)*N);
	for(unsigned int i=0;i<N;i++)
		sets[i]=i;
}
void union_(unsigned int x,unsigned int y){
	sets[y]=sets[x];
}
unsigned int find(unsigned int current){
	return sets[current];
}
