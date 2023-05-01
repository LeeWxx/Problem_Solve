#include <iostream>

using namespace std;

const int MAX_INPUT_VALUE = 8;

int output_arr[MAX_INPUT_VALUE] = {0, };

void print()
{
	int idx = 0; 
	
	while(output_arr[idx] != 0)
	{
		cout << output_arr[idx] << " ";
		idx++;
	}
	
	cout << "\n";
}

void solve(int idx, int N, int M, int last_num)
{
	if(idx == M)
	{
		print();
		return;
	}	
	
	for(int i=last_num; i<=N; i++)
	{
		if(!output_arr[idx])
			output_arr[idx] = i;
		
		solve(idx+1, N, M, i);
		
		output_arr[idx] = 0;
	}
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	solve(0, N, M, 1);
	
}