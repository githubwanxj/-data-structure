#include <stdio.h>
#include <stdlib.h>

int* shellSort(int array[], int length){
	int i,j,gap,k,temp;
	for(gap=length/2;gap>0;gap=gap/2){
		for(i=0;i<gap;i++){
			for(j=i+gap;j<length;j=j+gap){
				if(array[j]<array[j-gap]){
					temp=array[j];
					k=j-gap;
					while(k>=0 && array[k]>temp){
						array[k+gap]=array[k];
						k=k-gap;
					}
					array[k+gap]=temp;
				}
			}
		}
	}
	return array;
}

int main(void)
{
   int num[10]={5,4,8,0,3,4,2,1,7,9};
   int* res = shellSort(num,10);
   int i=0;
   for(i=0;i<10;i++){
   	printf("%d ", *res);
	res++;
   }
   return 0;
}	










