extern int Det_matrix ( int arr[][10] , int size );
extern int Matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] );
extern void Print_matrix ( int temp[][10] , int size );
extern void Transpose_matrix ( int arr[][10] , int temp[][10] , int size );
extern void Adjoint_matrix ( int arr[][10] , int temp[][10] , int size );
extern void Inverse_matrix ( int arr[][10] , float temp[][10] , int size );
void Add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size);
