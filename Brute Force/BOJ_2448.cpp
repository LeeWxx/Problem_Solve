#include <iostream>
#include <string>

using namespace std;

void change(string& output, int N, int start, int mid, int width)
{
	for(int i=(N-1) + start, k=0; i>=start; i--, k++)
	{
		for(int j=0; j<= k; j++)
		{
			int idx = i * (width + 1) + (mid - j);
			output[idx] = ' ';
			
			idx = i * (width + 1) + + (mid + j);
			output[idx] = ' ';
		}
	}
	
}

void solve(string& output, int start_y, int mid, int N, int base_width)
{	
	if(N == 3)
	{
		output[(base_width+1) * (start_y + 1) + mid] = ' ';
		return;
	}
	
	int y[3] = {start_y, start_y + N / 2, start_y + N / 2};
	int x[3] = {mid, mid - N / 2, mid + N / 2};
	
	for(int i=0; i<3; i++)
		solve(output, y[i], x[i], N/2, base_width);
	
	change(output, N/2, y[2], mid, base_width);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	int width = N * 2 - 1;
	int mid = N-1;
	
	string output;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(mid-i <= j && j <= mid+i)
				output += '*';
			else
				output += ' ';
		}
		
		output += '\n';
	}

	solve(output, 0, mid, N, width);
	
	cout << output;
	
	return 0;
}

