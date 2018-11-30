/**c语言实现归并排序，顺序存储结构**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 13

void sort(int *array,int startn,int endn){
	int i = 0;
	int j = 0;
	for(j=0;j<endn-startn;j++){
		for(i=startn;i<Size;i++){
			if(i+1<Size&&array[i]<array[i+1]){
				int tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
			}
		}
	}
}


int main(void)
{
   int array[Size]={34,56,7,99,74,12,53,51,1,2,0,100,2};
  // sort(array,0,Size);
   int i = 0;
   int gap = 2;
   int j = 0;

   for(i=0;gap<Size;gap*=2){
	for(j=0;j<Size;j++){
	  sort(array,j,j+gap);
	  j=j+gap+1;
	}
   } 
   printf("result: ");
   for(i=0;i<Size;i++){
   	printf("%d ",array[i]);
   }
   return 0;
}	









