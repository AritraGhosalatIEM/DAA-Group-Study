#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/param.h>
int main(int argc,char** argv){
	unsigned int space=atoi(argv[1])+1;
	unsigned int N=1,l;
	l=strlen(argv[2]);
	for(unsigned int i=0;i<l;i++)
		if(argv[2][i]==',')N++;
	int weight[N],profit[N];
	for(unsigned int i=0;i<N;i++){
		weight[i]=atoi(strtok_r(argv[2],",",&argv[2]));
		profit[i]=atoi(strtok_r(argv[3],",",&argv[3]));
	}
	int table[++N][space];
	for(unsigned int i=0;i<space;i++)table[0][i]=0;
	for(unsigned int i=1;i<N;i++){
		table[i][0]=0;
		for(unsigned int j=1;j<space;j++)
			if(j<weight[i-1])
				table[i][j]=table[i-1][j];
			else
				table[i][j]=MAX(table[i-1][j-weight[i-1]]+profit[i-1],table[i-1][j]);
	}
	printf("Total profit: %d\nBlocks included:\n",table[N-1][space-1]);
	unsigned int j=space-1;
	for(unsigned int i=N-1;j>0;i--)
		if(table[i][j]!=table[i-1][j]){
			printf("%d\n",i);
			j-=weight[i-1];
		}
	return 0;
}
