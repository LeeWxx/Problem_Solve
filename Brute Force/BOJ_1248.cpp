#include <iostream>

using namespace std;

const int MAX_INPUT = 10;

int input_arr[MAX_INPUT][MAX_INPUT];
int output[MAX_INPUT];

bool found = false;

void print(int N)
{
	for(int i=0; i<N; i++)
		cout << output[i] <<" ";
	
	cout << "\n";
}

bool check(int idx)
{
	int sum = 0;
	for(int i=idx; i>=0; i--)
	{
		sum += output[i];
		if(input_arr[idx][i] == 1)
		{
			if(sum <= 0)
				return false;
		}
		else if(input_arr[idx][i] == -1)
		{
			if(sum >= 0)
				return false;
		}
		else
		{
			if(sum != 0)
				return false;
		}
	}
	
	return true;
}

void solve(int N, int idx, int symbol)
{
	if(idx == N)
	{
		found = true;
		print(N);
		return;
	}
	
	if(symbol == 0)
	{
		output[idx] = 0;
		solve(N, idx+1, input_arr[idx+1][idx+1]);
		return;
	}
	
	for(int i=1; i<=10; i++)
	{	
		if(found)
			return;
		
		output[idx] = i * symbol;
		if(check(idx))
		{
			solve(N, idx+1, input_arr[idx+1][idx+1]);
		}
		else
			continue;
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	
	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			char input;
			cin >> input;
			if(input == '+')
				input_arr[j][i] = 1;
			else if(input == '-')
				input_arr[j][i] = -1;
			else
				input_arr[j][i] = 0;
		}
	}
	
	
	solve(N, 0, input_arr[0][0]);
}