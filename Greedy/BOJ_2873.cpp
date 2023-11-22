#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 1000;
int board[MAX_INPUT][MAX_INPUT];

string circSolve(pair<int, int> ban_pos, int R, int C)
{
	string output;
	
	int ban_y = ban_pos.first + 1;
	int ban_x = ban_pos.second + 1;
	
	for(int i=1; i<=R; i+=2)
	{
		if(i > ban_y)
		{
			for(int j=1; j<=C-1; j++)
				output += 'L';	
			
			output += 'D';
			
			for(int j=1; j<=C-1; j++)
				output += 'R';	
			
			if(i + 1 != R)
				output += 'D';
		}
		else if(i + 1 < ban_y)
		{
			for(int j=1; j<=C-1; j++)
				output += 'R';	
			
			output += 'D';
			
			for(int j=1; j<=C-1; j++)
				output += 'L';	
			
			if(i + 1 != R)
				output += 'D';
		}
		else
		{
			int y = i;
			int x = 1;
			
			int target_y = i+1;
			int target_x = C;
			
			char dir[4] = {'D', 'R', 'U', 'R'};
			int yn[4] = {1, 0, -1, 0};
			int xn[4] = {0, 1, 0, 1};
			
			int idx = 0;
			while(y != target_y || x != target_x)
			{
				int next_y = y + yn[idx];
				int next_x = x + xn[idx];
				
				if(next_y == ban_y && next_x == ban_x)
				{
					int next_idx;
					
					if(idx == 3)
						next_idx = 0;
					else
						next_idx = idx + 1;
					
					y = y + yn[next_idx];
					x = x + xn[next_idx];
					
					output += dir[next_idx];
				}
				else
				{
					y = next_y;
					x = next_x;
					
					output += dir[idx];
					
					if(idx == 3)
						idx = 0;
					else
						idx++;
				}
			}
			
			if(i + 1 != R)
				output += 'D';
		}
	}
	
	return output;
}

string directSolve(int R, int C)
{
	string output;
	
	if(R % 2 == 1 && C % 2 == 1)
	{
		for(int i=1; i<=R; i++)
		{
			for(int j=1; j<=C-1; j++)
			{
				if(i % 2 == 1)
					output += 'R';
				else
					output += 'L';
			}
			
			if(i != R)
				output += 'D';
		}
	}
	
	
	if(R % 2 == 0 && C % 2 == 1)
	{
		for(int j=1; j<=C; j++)
		{
			for(int i=1; i<=R-1; i++)
			{
				if(j % 2 == 1)
					output += 'D';
				else
					output += 'U';
			}
			
			if(j != C)
				output += 'R';
		}
	}
	
	if(R % 2 == 1 && C % 2 == 0)
	{
		for(int i=1; i<=R; i++)
		{
			for(int j=1; j<=C-1; j++)
			{
				if(i % 2 == 1)
					output += 'R';
				else
					output += 'L';
			}
			
			if(i != R)
				output += 'D';
		}
	}
	
	return output;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int R, C;
	cin >> R >> C;
	
	int ban_num(MAX_INPUT);
	pair<int, int> ban_pos;
	
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{	
			cin >> board[i][j];
			
			if((i + j) % 2 == 1)
			{
				if(ban_num > board[i][j])
				{
					ban_num = board[i][j];
					ban_pos = make_pair(i, j);
				}
			}
		}
	}
	
	string output;
	
	if(R % 2 == 0 && C % 2 == 0)
		output = circSolve(ban_pos, R, C);
	else 
		output = directSolve(R, C);
	
	cout << output << "\n";
}







