#include <stdio.h>
#include <stdlib.h>

#define max 100
#define vexnum 3
#define edgenum 5
int edge[edgenum][2]={0};
int vex[vexnum]={0};
typedef struct _enode{//边结点
	int distance;
	int start;//起点
	int end;//终点
	struct _enode* nextedge;
}enode;
typedef struct _vnode{//头结点
	int vex;
	enode* firstedge;	
}vnode;
typedef struct _adj{
	int vex_num;
	int edge_num;
	vnode node[max];
}adj;
void find_insert(enode *edge,enode* tmp){
	enode* p;
	p=edge;
	while(p->nextedge!=NULL){
		p=p->nextedge;
	}
	p->nextedge=tmp;
}
adj* create_adj(){
	printf("start create...\n");
	int i=0,c1,c2,j=0;
	enode * node_temp;
	adj* list;
	list=(adj*)malloc(sizeof(adj));
	list->edge_num=edgenum;
	list->vex_num=vexnum;
	for(i=0;i<=vexnum;i++){
		list->node[i].vex=vex[i];
		list->node[i].firstedge=NULL;
		printf("%d\n",list->node[i].vex);
	}	
	for(i=0;i<list->edge_num;i++){
		c1=edge[i][0];//起点
		c2=edge[i][1];//终点
		node_temp=(enode*)malloc(sizeof(struct _enode));
		node_temp->distance=0;
		node_temp->start=c1;
		node_temp->end=c2;
		node_temp->nextedge=NULL;
		for(j=0;j<list->vex_num;j++){
			if(list->node[j].vex==c1){
				if(list->node[j].firstedge==NULL){
					list->node[j].firstedge=node_temp;
				}else{
					find_insert(list->node[j].firstedge,node_temp);
				}
			}
		}
	}
	printf("ok!\n");
	return list;
}




/**adjacency list**/
int main(void)
{
   int i=0;
   adj* list;
   printf("ver：");
   for(i=0;i<vexnum;i++){
   	scanf("%d",&vex[i]);
   }
   printf("edge:\n");
   for(i=0;i<edgenum;i++){
   	scanf("%d",&edge[i][0]);
	scanf("%d",&edge[i][1]);
   }
   list=create_adj();
   printf("result:\n");
   for(i=0;i<list->vex_num;i++){
   	enode* p=(enode*)malloc(sizeof(enode));
	printf("%d",list->node[i].vex);
	p=list->node[i].firstedge;
	if(p!=NULL){
		printf("->%d",p->end);
		p=p->nextedge;
		while(p!=NULL){
			printf("->%d",p->end);
			p=p->nextedge;
		}
	}
	printf("\n");
   }
   return 0;
}	









