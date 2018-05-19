#include<stdio.h>

int det_matrix ( int arr[][10] , int size );
int matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] );
void print_matrix ( int temp[][10] , int size );
void transpose_matrix ( int arr[][10] , int temp[][10] , int size );
void cofactor_matrix ( int arr[][10] , int temp[][10] , int size );
void inverse_matrix ( int arr[][10] , float temp[][10] , int size );
void add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size);



int det_matrix ( int arr[][10] , int size )                      // Finds the determinant of a matrix arr of size * size
{
	int res = 0,i;
	int temp[10][10];
	int sign = 1;
	if (size == 2)
	{
		res = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
	}
	else
	{
		for (i=0 ; i<size ; i++)
		{
			int temp_size = matrix_ret( arr , size , 0 , i , temp);
			res = res + det_matrix(temp,temp_size)*sign*arr[0][i];
			sign = -1*sign;
		}
	}
		return res;
}





int matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] )   
{
	int i,j,u=0,v=0;
	for (i=0 ; i<size ; i++)
	{
		if (i!=row_start)
		{
			for (j=0 ; j<size ; j++)
			{
				if (j!=col_start)
				{
					temp[u][v]=arr[i][j];
					v++;
				}
			}
			u++;
			v=0;
		}
	}
	return u;
}



void print_matrix ( int temp[][10] , int size )
{
	int i,j;
	for (i=0 ; i<size ; i++)
	{
		for (j=0 ; j<size ; j++)
		{
			printf("%-3d ",temp[i][j]);
		}
		printf("\n");
	}
}




void transpose_matrix ( int arr[][10] , int temp[][10] , int size )
{
	int i,j;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			temp[i][j]=arr[j][i];
		}
	}
}



void adjoint_matrix ( int arr[][10] , int temp[][10] , int size )
{
	int i,j;
	int temp1[size][size];
	int u = size-1, sign = 1;
	for ( i=0 ; i<size ; i++ )
	{
		for ( j=0 ; j<size ; j++ )
		{
			matrix_ret(arr,size,i,j,temp1);
			temp[j][i]=sign*det_matrix(temp1,u);
			sign=-1*sign;
		}
	}
}




void inverse_matrix ( int arr[][10] , float temp[][10] , int size )
{
	int det = det_matrix(arr,size);
	int i,j, temp1[10][10];
	adjoint_matrix( arr, temp1 , size);
	if (det==0)
	{printf("Inverse does not exists.\n");}
	else
	{
		for ( i=0 ; i<size ; i++)
		{
			for ( j=0 ; j<size ; j++ )
			{
				temp[i][j] =  ((float)temp1[i][j]) / det ;
				printf("%6.3lf ",temp[i][j]);
			}
			printf("\n");

		}
	}	
}

void add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size)
{
	int i,j;
	for ( i=0 ; i<size ; i++ )
	{
		for ( j=0 ; j<size ; j++ )
		{
			temp[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
}


