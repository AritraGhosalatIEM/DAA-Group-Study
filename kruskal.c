#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
unsigned int *sets;
void quicksort(unsigned int dimension,unsigned int begin,unsigned int len,int (*arr)[dimension][len]){
	if(begin==len)return;
	unsigned int from_left=begin,from_right;
	int pivot=(*arr)[0][from_right=len-1],t;
	while(from_left<from_right){
		for(;(*arr)[0][from_left]<pivot && from_left<from_right;from_left++);
		for(;(*arr)[0][from_right]>=pivot && from_left<from_right;from_right--);
		for(unsigned int i=0;i<dimension;i++){//swap
			t=(*arr)[i][from_left];
			(*arr)[i][from_left]=(*arr)[i][from_right];
			(*arr)[i][from_right]=t;
		}
	}
	for(unsigned int i=0;i<dimension;i++){//swap
		t=(*arr)[i][from_left];
		(*arr)[i][from_left]=(*arr)[i][len-1];
		(*arr)[i][len-1]=t;
	}
	quicksort(dimension,begin,from_right,arr);
	quicksort(dimension,from_right+1,len,arr);
}
void initialize(unsigned int N){
	sets=(unsigned int*)malloc(sizeof(int)*N);
	for(unsigned int i=0;i<N;i++)
		sets[i]=i;
}
void union_(unsigned int x,unsigned int y){
	sets[y]=sets[x];
}
unsigned int find(unsigned int current){
	return sets[current];
}
int main(int argc,char** argv){
	//input
	unsigned int N=0,connections=0;
	FILE* file=fopen("graph.csv","r");
	int c;
	for(;;){
		if(!fscanf(file,",%d",&c))
			if(fscanf(file,"%d",&c)==-1)break;
			else N++;
		if(c!=0)connections++;
	}
	rewind(file);
	int (*mst)[N][N]=calloc(N,N*sizeof(int));
	int (*edges)[3][connections]=calloc(3,connections*sizeof(int));
	connections=0;
	for(unsigned int i=0;i<N;i++){
		fscanf(file,"%d",&c);
		if(c!=0){
			(*edges)[0][connections]=c;
			(*edges)[1][connections]=i;
			(*edges)[2][connections++]=0;
		}
		for(unsigned int j=1;j<N;j++){
			fscanf(file,",%d",&c);
			if(c!=0){
				(*edges)[0][connections]=c;
				(*edges)[1][connections]=i;
				(*edges)[2][connections++]=j;
			}
		}
	}
	fclose(file);
	quicksort(3,0,connections,edges);
	initialize(N);
	for(unsigned int i=0;i<connections;i++)//iterate over sorted edges
		if(find((*edges)[1][i])!=find((*edges)[2][i])){//if two nodes aren't connection
			(*mst)[(*edges)[1][i]][(*edges)[2][i]]=(*edges)[0][i];//connect in mst
			union_((*edges)[1][i],(*edges)[2][i]);
		}
	return 0;
}
