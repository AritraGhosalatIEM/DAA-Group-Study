//https://en.wikipedia.org/wiki/Longest_common_subsequence
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef enum dir{ UP,
	LEFT,
	DIAGONAL
} __attribute__((__packed__)) Direction;
void subsequence(unsigned int rows,unsigned int columns,Direction (*direction)[rows][columns],unsigned int (*table)[rows][columns],char* sequence,unsigned int row,unsigned int column){
	if((*table)[row][column]!=0)
		switch((*direction)[row][column]){
			case DIAGONAL:
				subsequence(rows,columns,direction,table,sequence,row-1,column-1);
				printf("%c",sequence[row-1]);
				break;
			case UP:
				subsequence(rows,columns,direction,table,sequence,row-1,column);
				break;
			case LEFT:
				subsequence(rows,columns,direction,table,sequence,row,column-1);
				break;
		}
}
int main(int argc,char** argv){
	unsigned int l1=strlen(argv[1]),l2=strlen(argv[2]);
	Direction (*direction)[l1+1][l2+1]=malloc(sizeof(*direction));
	unsigned int (*table)[l1+1][l2+1]=malloc(sizeof(*table));
	for(unsigned int i=0;i<=l1;i++)(*table)[i][0]=0;//first column
	for(unsigned int i=0;i<=l2;i++)(*table)[0][i]=0;//first row
	for(unsigned int i=1;i<=l1;i++){
		for(unsigned int j=1;j<=l2;j++){
			if(argv[1][i-1]==argv[2][j-1]){
				(*table)[i][j]=(*table)[i-1][j-1]+1;
				(*direction)[i][j]=DIAGONAL;
			}
			else if((*table)[i][j-1]>(*table)[i-1][j]){
				(*table)[i][j]=(*table)[i][j-1];
				(*direction)[i][j]=LEFT;
			}
			else{
				(*table)[i][j]=(*table)[i-1][j];
				(*direction)[i][j]=UP;
			}
		}
	}
	printf("Size of subsquence: %d\nSubsequence: ",(*table)[l1][l2]);
	subsequence(l1+1,l2+1,direction,table,argv[1],l1,l2);
	printf("\n");
	return 0;
}
