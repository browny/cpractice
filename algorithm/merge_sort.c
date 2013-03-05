#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void divide(int num[],int start,int end);
void merge(int num[],int start,int mid,int end);
void dump(int num[],int size);

#define ARRAY_SIZE 10

int main(int argc, char** argv)
{
	int *num = (int *)malloc(sizeof(int)*ARRAY_SIZE);
	int i = 0;

	srand(time(NULL));
	for(i=0;i<ARRAY_SIZE;i++)
		num[i] = rand()%50+1;

	dump(num,ARRAY_SIZE);
	divide(num,0,ARRAY_SIZE-1);
	dump(num,ARRAY_SIZE);

	free(num);
	return 0;
}

void divide(int num[],int start,int end)
{
	int mid = (start+end)/2;

	if(start != end) {
		divide(num,start,mid);
		divide(num,mid+1,end);
		merge(num,start,mid,end);
	}
}

void merge(int num[],int start,int mid,int end)
{
	int *temp = (int *)malloc(sizeof(int) * (end-start+1));
	int i = start, j = mid+1, k = 0;

	while(k <= (end-start)) {
		if(i > mid) {
			temp[k] = num[j];
			j++;
		} else if (j > end) {
			temp[k] = num[i];
			i++;
		} else {
			if(num[i] <= num[j]) {
				temp[k] = num[i];
				i++;
			} else {
				temp[k] = num[j];
				j++;
			}
		}
		k++;
	}

	for(i=start; i<=end ;i++)
		num[i] = temp[i-start];

	free(temp);
}

void dump(int num[],int size)
{
	int i = 0;
	for(i=0;i<size;i++)
		printf("%3d ",num[i]);
	printf("\n");
}
