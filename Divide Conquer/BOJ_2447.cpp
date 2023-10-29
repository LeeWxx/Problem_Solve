#include <iostream>
#include <string>

using namespace std;

int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};

void change(string& str, int start_y, int start_x, int N, int length)
{
	for(int i=0; i<length; i++)
	{
		for(int j=0; j<length; j++)
		{
			int idx = ((start_y + i) * (N+1))  + (start_x + j);
			str[idx] = ' ';
		}
	}
}

void solve(string& str, int start_y, int start_x, int N, int length)
{
	if(length == 1)
		return;

	int next_length = length / 3;
	
	for(int i=0; i<9; i++)
	{
		int next_y = start_y + (dy[i] * next_length);
		int next_x = start_x + (dx[i] * next_length);
		
		if(i == 4)
		{
			change(str, next_y, next_x, N, next_length);
		}
		else
		{
			solve(str, next_y, next_x, N, next_length);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	string output;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			output += '*';
		}
		
		output += '\n';
	}
	
	solve(output, 0, 0, N, N);
	
	cout << output;
	
	return 0;
}
