#include <iostream>

using namespace std;

char inequality_arr[9];
int output_arr[10];
bool checked_arr[10];

bool is_found = false;

void print(int N)
{
	for(int i=0; i<N-1; i++)
		cout << output_arr[i];
	
	cout << output_arr[N-1] << endl;
}

bool inequalityCheck(int N)
{
	for(int i=0; i<N; i++)
	{
		if(inequality_arr[i] == '>')
		{
			if(output_arr[i] < output_arr[i+1])
				return false;		
		}
		else if(inequality_arr[i] == '<')
		{
			if(output_arr[i] > output_arr[i+1])
				return false;	
		}
	}
	
	return true;
}

void solve(int N, int idx, int start, int end)
{
	
	if(idx==N+1)
	{
		if(inequalityCheck(N))
		{
			is_found = true;
			print(N+1);
		}
		return;
	}
	
	int i = start;
	
	while(i != end)
	{
		if(is_found)
			return;
		
		if(checked_arr[i])
		{
			if(start < end)
				i++;
			else
				i--;
		
			continue;
		}
		
		output_arr[idx] = i;
		checked_arr[i] = true;
		solve(N, idx+1, start, end);
		checked_arr[i] = false;
		
		
		if(start < end)
			i++;
		else
			i--;
		
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
		cin >> inequality_arr[i];
	
	solve(N, 0, 9, -1);
	
	is_found = false;
	for(int i=0; i<=N; i++)
	{
		checked_arr[i] = false;
		output_arr[i] = 0;
	}
	
	solve(N, 0, 0, 10);
}