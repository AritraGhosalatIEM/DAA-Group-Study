#include<stdlib.h>
#include<stdarg.h>
int** pq;
unsigned int arrays,pq_items;
void _swap(unsigned int x,unsigned int y){
	int t;
	for(int i=0;i<arrays;i++){
		t=pq[i][x];
		pq[i][x]=pq[i][y];
		pq[i][y]=t;
	}
}
void build_heap(){
	unsigned int current,swap_index,right_child,left_child;
	for(int i=(pq_items-1)/2;i>=0;i--){
		current=i;
		do{
			left_child=2*current+1;
			right_child=2*current+2;
			swap_index=(right_child<pq_items && pq[0][right_child]<pq[0][left_child])?right_child:left_child;
			if(pq[0][swap_index]>=pq[0][current])
				break;
			_swap(current,swap_index);
			current=swap_index;
		}while(current<=(pq_items-1)/2);
	}
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
unsigned int insert(...){
	pq_items++;
	va_list values;
	va_start(values,arrays);
	int key=va_arg(values,int);
	for(unsigned int i=1;i<arrays;i++)
		pq[i][pq_items]=va_arg(values,int);
	va_end(values);
	return bubble_up(pq_items-1,key);
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
int main(){
	//testing
	int key[]={13,75,95,35,21,29,17,31,36,82};
	int val1[]={39,65,60,90,30,99,3,39,63,57};
	int val2[]={98,11,90,95,15,80,92,8,68,63};
	pq_items=10;
	arrays=3;
	int* a[]={key,val1,val2};
	pq=a;
	build_heap();
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	printf("%d\n",poll(0));
	return 0;
}
