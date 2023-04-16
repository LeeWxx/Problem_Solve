#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void cellSwap(char board_line[], int a, int b)
{
	char temp = board_line[a];
	board_line[a] = board_line[b];
	board_line[b] = temp;
}

int getLength(char board_line[], int size)
{
	int max(0);
	int count(1);
	char ch = board_line[0];
	
	for(int i=1; i<size; i++)
	{		
		if(board_line[i] == ch)
		{
			count++;
		}
		else
		{
			if(max < count)
				max = count;
			count = 1;
		}
		
		ch = board_line[i];
	}
		
	if(max < count)
		max = count;
	
	return max;
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int output(0);
	
	char **board = new char*[N];
	char **temp_board = new char*[N];
	
	for(int i=0; i<N; i++)
		board[i] = new char[N+1];
	
	for(int i=0; i<N; i++)
		temp_board[i] = new char[N];
	
	cin.ignore();
	for(int i=0; i<N; i++)
	{
		cin.getline(board[i], N+1);
	}
	
	for(int j=0; j<N; j++)
	{
		output = max(output, getLength(board[j], N));
	}
	for(int i=0; i<N; i++)
	{
		char* board_line = new char[N];
				
		for(int k = 0; k<N; k++)
		{
			board_line[k] = board[k][i];
		}
			
		output = max(output, getLength(board_line, N));
		delete[] board_line;
	}
	for(int q=0; q<2; q++)
	{
		for(int j=0; j<N; j++)
		{
			for(int i=0; i<N-1; i++)
			{
				if(board[j][i] != board[j][i+1])
				{
					cellSwap(board[j], i, i+1);
			
					char* left_board_line = new char[N];
					char* right_board_line = new char[N];
				
					for(int k = 0; k<N; k++)
					{
						left_board_line[k] = board[k][i];
						right_board_line[k] = board[k][i+1];
					}
			
					int a = getLength(board[j], N);
					int b = getLength(left_board_line, N);
					int c = getLength(right_board_line, N);
					
					output = max({a,b,c,output});
					cellSwap(board[j], i, i+1);
				
					delete[] left_board_line;
					delete[] right_board_line;
				}
			}		
		}
		
		if(q == 0)
		{	
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					temp_board[i][j] = board[j][i];
				}
			}
			
			for(int i=0; i<N; i++)
			{
				memmove(board[i],temp_board[i],N);	
			}
		}
	}
	
	
	cout << output << endl;
	
	for(int i=0; i<N; i++)
		delete[] board[i];
	
	for(int i=0; i<N; i++)
		delete[] temp_board[i];
	
	delete[] board;
	delete[] temp_board;
}