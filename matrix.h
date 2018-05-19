extern int det_matrix ( int arr[][10] , int size );
extern int matrix_ret ( int arr[][10], int size , int row_start , int col_start, int temp[][10] );
extern void print_matrix ( int temp[][10] , int size );
extern void transpose_matrix ( int arr[][10] , int temp[][10] , int size );
extern void adjoint_matrix ( int arr[][10] , int temp[][10] , int size );
extern void inverse_matrix ( int arr[][10] , float temp[][10] , int size );
void add_matrix (int arr1[][10] , int arr2[][10] , int temp[][10] , int size);