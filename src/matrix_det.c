#include<stdio.h>

int Det_matrix ( int arr[][10] , int size );
int Matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] );
void Print_matrix ( int temp[][10] , int size );
void Transpose_matrix ( int arr[][10] , int temp[][10] , int size );
void Cofactor_matrix ( int arr[][10] , int temp[][10] , int size );
void Inverse_matrix ( int arr[][10] , float temp[][10] , int size );
void Add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size);
void Adjoint_matrix ( int arr[][10] , int temp[][10] , int size );


int Det_matrix ( int arr[][10] , int size )                      // Finds the determinant of a matrix arr of size * size
{
	int res = 0,i;
	int temp[10][10];
	int sign = 1;
	if(size == 1){
		return arr[0][0];
	}

	if (size == 2)
	{
		res = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
	}
	else
	{
		for (i=0 ; i<size ; i++)
		{
			int temp_size = Matrix_ret( arr , size , 0 , i , temp);
			res = res + Det_matrix(temp,temp_size)*sign*arr[0][i];
			sign = -1*sign;
		}
	}
		return res;
}





int Matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] )   
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


/* 
 *
 */
void Print_matrix ( int temp[][10] , int size )
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




void Transpose_matrix ( int arr[][10] , int temp[][10] , int size )
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



void Adjoint_matrix ( int arr[][10] , int temp[][10] , int size )
{
	int i,j;
	int temp1[size][size];
	int u = size-1, sign = 1;
	for ( i=0 ; i<size ; i++ )
	{
		for ( j=0 ; j<size ; j++ )
		{
			Matrix_ret(arr,size,i,j,temp1);
			temp[j][i]=sign*Det_matrix(temp1,u);
			sign=-1*sign;
		}
	}
}




void Inverse_matrix ( int arr[][10] , float temp[][10] , int size )
{
	int det = Det_matrix(arr,size);
	int i,j, temp1[10][10];
	Adjoint_matrix( arr, temp1 , size);
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

void Add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size)
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

