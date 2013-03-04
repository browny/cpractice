#include <stdio.h>
#include <stdlib.h>

void quick_sort(int num[],int start,int end);
void swap(int num[],int index_a,int index_b);
void dump(int num[]);

int main(int argc, char** argv)
{
	int num[10] = {12,34,22,66,41,87,74,35,22,17};
	//int num[10] = {10,9,8,7,6,5,4,3,2,1};
	//int num[10] = {1,2,3,4,5,6,7,8,9,10};

	dump(num);
	quick_sort(num,0,9);
	dump(num);

	return 0;
}

void quick_sort(int num[],int start,int end)
{
	int i = 0,j = 0,pivot = 0;

	if(start < end) {
		pivot = num[(start+end)/2];
		i = start - 1;
		j = end + 1;

		while(i<j) {
			do
				i++;
			while(num[i]<pivot);

			do
				j--;
			while(num[j]>pivot);

			if(i<j)
				swap(num,i,j);
		}
		quick_sort(num,start,i-1);
		quick_sort(num,j+1,end);
	}
}

void swap(int num[],int index_a,int index_b)
{
	num[index_a] = num[index_a] + num[index_b];
	num[index_b] = num[index_a] - num[index_b];
	num[index_a] = num[index_a] - num[index_b];
}

void dump(int num[])
{
	int i = 0;
	for(i=0;i<10;i++)
		printf("%3d ",num[i]);
	printf("\n");
}
