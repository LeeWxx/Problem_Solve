#include <iostream>
using namespace std;

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

void getTranspose(int arr[], int &col, int &row)
{
	int size = row * col;
	int* temp = new int[size]; 
	
	for (int i = 0; i < size; i++)
	{
        temp[i] = arr[i];
    }
	
	for(int j=0; j<row; j++)
	{
		for(int i=0; i<col; i++)
		{
			arr[j * col + i] = temp[ i * row + j];
		}
	}
	
	int tmp = col;
	col = row;
	row = tmp;
	
	delete[] temp;
}

void getHorizontalSymmetry(int arr[], int col, int row)
{
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<(row/2); j++)
		{
			int temp = arr[(i * row)+ (row-(j+1))];
			arr[(i * row)+ (row-(j+1))] = arr[(i * row) + j];
			arr[(i * row) + j] = temp;
		}
	}
}

void getVerticalSymmetry(int arr[], int col, int row)
{
	for(int j=0; j<row; j++)
	{
		for(int i=0; i<col/2; i++)
		{
			int temp = arr[row * (col-(i+1)) + j];
			arr[row * (col-(i+1)) + j] = arr[(i * row) + j];
			arr[(i * row) + j] = temp;
		}	
	}
}

void L_Tetromino(int arr[], int col, int row, int& max_value)
{	
	int width(2);  
	int	height(3);
	
	for(int i=0; i<(col-height)+1; i++)
	{
		for(int j=0; j<(row-width)+1; j++)
		{
			int sum(0);
			
			sum += arr[(row * i) + j];
			sum += arr[(row * (i+1)) + j];
			sum += arr[(row * (i+2)) + j];
			sum += arr[(row * (i+2)) + j + 1];
			
			max_value = max(sum,max_value);
		}
	}
}

void S_Tetromino(int arr[], int col, int row, int& max_value)
{	
	int width(2);  
	int	height(3);
	
	for(int i=0; i<(col-height)+1; i++)
	{
		for(int j=0; j<(row-width)+1; j++)
		{
			int sum(0);
			
			sum += arr[(row * i) + j];
			sum += arr[(row * (i+1)) + j];
			sum += arr[(row * (i+1)) + j + 1];
			sum += arr[(row * (i+2)) + j + 1];
			
			max_value = max(sum,max_value);
		}
	}
}

void T_Tetromino(int arr[], int col, int row, int& max_value)
{	
	int width(3);  
	int	height(2);
	
	for(int i=0; i<(col-height)+1; i++)
	{
		for(int j=0; j<(row-width)+1; j++)
		{
			int sum(0);

			sum += arr[(row * i) + j];
			sum += arr[(row * i) + j + 1];
			sum += arr[(row * (i+1)) + j + 1];
			sum += arr[(row * i) + j + 2];
			
			max_value = max(sum,max_value);
		}
	}
}

void O_Tetromino(int arr[], int col, int row, int& max_value)
{	
	int width(2);  
	int	height(2);
	
	for(int i=0; i<(col-height)+1; i++)
	{
		for(int j=0; j<(row-width)+1; j++)
		{
			int sum(0);
		
			sum += arr[(row * i) + j];
			sum += arr[(row * i) + j + 1];
			sum += arr[(row * (i+1)) + j];
			sum += arr[(row * (i+1)) + j + 1];
			
			max_value = max(sum,max_value);
		}
	}
}

void I_Tetromino(int arr[], int col, int row, int& max_value)
{	
	int width(1);  
	int	height(4);
	
	for(int i=0; i<(col-height)+1; i++)
	{
		for(int j=0; j<(row-width)+1; j++)
		{
			int sum(0);

			sum += arr[(row * i) + j];
			sum += arr[(row * (i+1)) + j];
			sum += arr[(row * (i+2)) + j];
			sum += arr[(row * (i+3)) + j];
			
			max_value = max(sum,max_value);
		}
	}
}

void getMaxValue(int arr[], int col, int row, int& max_value)
{
	L_Tetromino(arr, col, row, max_value);
	S_Tetromino(arr, col, row, max_value);
	T_Tetromino(arr, col, row, max_value);
	O_Tetromino(arr, col, row, max_value);
	I_Tetromino(arr, col, row, max_value);
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int M;
	
	cin >> N >> M;
	
	int* board = new int[N * M];
	int output(0);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cin >> board[(i * M)+ j];
		}
	}
	
	for(int i=1; i<=8; i++)
	{
		getMaxValue(board, N, M, output);
		
		if(i % 2 == 0)
			getVerticalSymmetry(board, N, M);
		if(i % 2 != 0)
			getHorizontalSymmetry(board, N, M);
		if(i % 4 ==0)
			getTranspose(board, N, M);
	}
	
	
	cout << output << endl;
	
	delete[] board;
}