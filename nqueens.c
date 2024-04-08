#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
unsigned int* positions;
unsigned int N;
void queen(unsigned int row){
	if(row==N){//complete
		for(unsigned int i=0;i<N;i++)
			printf("(%d,%d) ",i,positions[i]);
		printf("\n");
		return;
	}
	for(unsigned int column=0;column<N;column++){
		for(unsigned int i=0;i<row;i++){//check with previous pieces
			if(positions[i]==column)goto next;//same column
			if(positions[i]-i==column-row || positions[i]+i==column+row)goto next;//same diagonal
		}
		positions[row]=column;
		queen(row+1);
		next:
	}
}
int main(int argc,char** argv){
	N=atoi(argv[1]);
	positions=malloc(N*sizeof(int));
	queen(0);
	return 0;
}
