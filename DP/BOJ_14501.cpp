#include <iostream>

const int MAX_INPUT_DAY = 15;

int T_arr[MAX_INPUT_DAY];
int P_arr[MAX_INPUT_DAY];

int max_profit(0);

using namespace std;

void solve(int idx, int wait_count, int N, int profit)
{
	if(idx == N)
	{
		max_profit = max(max_profit, profit);
		return;
	}
	
	if(T_arr[idx] <= N - idx && wait_count <= 0)
		solve(idx + 1, T_arr[idx] - 1, N, profit + P_arr[idx]);
	
	solve(idx + 1, wait_count - 1, N, profit);
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> T_arr[i];
		cin >> P_arr[i];
	}
	
	solve(0, 0, N, 0);
	
	cout << max_profit << endl;
}