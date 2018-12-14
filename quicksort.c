#include <stdio.h>
#include <stdlib.h>

int a[10]= {5,4,28,10,3,4,2,1,7,9},n;
void quicksort(int left,int right){
	int i,j,t,temp;
	if(left>right){
		return;
	}
	temp = a[left];
	i=left;
	j=right;
	while(i!=j){
		while(a[j]>=temp && i<j)
			j--;
		while(a[i]<=temp && i<j)
			i++;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksort(left,i-1);
	quicksort(i+1,right);

}

int main(void)
{
   quicksort(0,9);
   int i=0;
   for(i=0;i<10;i++){
   	printf("%d ", a[i]);
   }
   return 0;
}	










