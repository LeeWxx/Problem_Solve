#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX_SIZE = 500;
bool board[MAX_SIZE][MAX_SIZE];

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	memset(board, false, sizeof(board));
	
	int H, W;
	cin >> H >> W;
	
	for(int j=0; j<W; j++)
	{
		int h;
		cin >> h;
		
		for(int i=0; i<h; i++)
			board[i][j] = true;
	}
	
	int result = 0;

	for(int i=0; i<H; i++)
	{
		bool is_open = false;
		int sum = 0;
		
		for(int j=0; j<W; j++)
		{
			if(is_open && !board[i][j])
				sum++;
			else if(!is_open && board[i][j])
				is_open = true;
			else if(is_open && board[i][j])
			{
				result += sum;
				sum = 0;
			}
		}
		
	}
	
	cout << result << "\n";
}