#include<stdio.h>
#include<stdlib.h>
#include<sys/param.h>
int main(int argc,char** argv){
	unsigned int size[argc];
	sscanf(argv[1],"%dx%*d",&size[0]);
	for(unsigned int i=1;i<argc;i++)
		sscanf(argv[i],"%*dx%d",&size[i]);
	unsigned int N=argc-1;
	int** table=(int**)malloc(N*sizeof(int*));
	for(unsigned int i=0;i<N;i++){
		table[i]=(int*)malloc((N-i)*sizeof(int));
		table[i][0]=0;
	}
	for(unsigned int column=1;column<N;column++){
		for(unsigned int row=0;row<N-1;row++){
			unsigned int i=row+1;
			unsigned int j=column+row+1;
			unsigned int min=-1;
			for(unsigned int k=i
		}
	}
	return 0;
}
