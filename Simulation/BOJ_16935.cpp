#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int board[MAX_SIZE][MAX_SIZE];
int temp_board[MAX_SIZE][MAX_SIZE];


void printBoard(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			cout << board[i][j] << " ";
	
		cout << "\n";
	}
	
}

void flipUpDown(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			board[i][j] = temp_board[N-1-i][j];
	}
}

void flipLeftRight(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			board[i][j] = temp_board[i][M-1-j];
	}
}

void rotateRight(int& N, int& M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			board[j][N-1-i] = temp_board[i][j];
	}
	
	int temp = N;
	N = M;
	M = temp;
	
}

void rotateLeft(int& N, int& M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			board[M-j-1][i] = temp_board[i][j];
	}
	
	int temp = N;
	N = M;
	M = temp;
}

void moveRightWithDivision(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	// 4 -> 1
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[i][j] = temp_board[N/2+i][j];
		}
	}
	
	// 1 -> 2
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[i][M/2+j] = temp_board[i][j];
		}
	}
	
	// 2 -> 3
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[N/2+i][M/2+j] = temp_board[i][M/2+j];
		}
	}
	
	// 3 -> 4
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[N/2+i][j] = temp_board[N/2+i][M/2+j];
		}
	}
}

void moveLeftWithDivision(int N, int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			temp_board[i][j] = board[i][j];
	}
	
	// 1 -> 4
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[N/2+i][j] = temp_board[i][j];
		}
	}
	
	// 2 -> 1
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[i][j] = temp_board[i][M/2+j];
		}
	}
	
	// 3 -> 2
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[i][M/2+j] = temp_board[N/2+i][M/2+j];
		}
	}
	
	// 4 -> 3
	for(int i=0; i<N/2; i++)
	{
		for(int j=0; j<M/2; j++)
		{
			board[N/2+i][M/2+j] = temp_board[N/2+i][j];
		}
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	int N, M, R;
	cin >> N >> M >> R;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			cin >> board[i][j];
	}
	
	for(int i=0; i<R; i++)
	{
		int instr;
		cin >> instr;
		
		switch(instr)
		{
			case 1:
				flipUpDown(N, M);
				break;
			case 2:
				flipLeftRight(N, M);
				break;
			case 3:
				rotateRight(N, M);
				break;
			case 4:
				rotateLeft(N, M);
				break;
			case 5:
				moveRightWithDivision(N, M);
				break;
			case 6:
				moveLeftWithDivision(N, M);
				break;
		}
	}
	
	printBoard(N, M);
}