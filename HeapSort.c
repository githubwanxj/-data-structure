#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

/**生成小根树**/
void HeapSort(int A[],int N){
	int i;
	int n;
	if(N%2==0){
		n=N;	
	}else{
		int f=ceil(N/2)-1;
		if(A[f]>A[N]){
			Swap(&A[f],&A[N]);
		}
		n=N-1;
	}
	for(i=n;i>=2;){
		int f=ceil(i/2)-1;
		int min = i;
		if(A[i]>A[i-1]){
			min=i-1;
		}
		if(A[min]<A[f]){
			Swap(&A[min],&A[f]);
		}
		i=i-2;		
	}
	if(A[0]>A[1]){
		Swap(&A[0],&A[1]);
	}
	int tmp=A[N];
	A[N]=A[0];
	A[0]=tmp;
	if(N-1>0){
		HeapSort(A,N-1);
	}
}

void Print(int A[],int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",A[i]);
	}
}

int main(void)
{
   int arr[10] = {62,87,39,49,34,62,53,6,44,98}; 
   Print(arr,10);
   printf("\n");
   HeapSort(arr,9);
   printf("\n");
   Print(arr,10);
   return 0;
}	










