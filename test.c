#include<stdio.h>
#include "include/matrix.h"
void main()
{
	int size,i,j,arr[10][10];
	int temp[10][10];
	printf("Enter size : ");
	scanf("%d",&size);

	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	Adjoint_matrix(arr, temp, size);
	Print_matrix(temp, size);
	printf("%d\n", Det_matrix(arr, size));
}
