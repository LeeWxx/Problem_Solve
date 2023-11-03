#include <iostream>

using namespace std;

const int MAX_INPUT = 100000;

int post_order[MAX_INPUT+1];
int idx_arr[MAX_INPUT+1];

void input(int N)
{
	for(int i=1; i<=N; i++)
	{
		int x;
		cin >> x;
		int num = x;
		idx_arr[num] = i;
	}
	
	for(int i=1; i<=N; i++)
		cin >> post_order[i];
}

void solve(int in_start, int in_end, int post_start, int post_end)
{
	
	if(in_start > in_end || post_start > post_end)
		return;
	
	int pick = post_order[post_end];
	cout << pick << " ";
	int in_idx = idx_arr[pick];
	
	int left_size = in_idx - in_start;
	int right_size = in_end - in_idx;
	
	solve(in_start, in_idx-1, post_start, post_start + left_size - 1);
	solve(in_idx+1, in_end, post_end - right_size, post_end-1);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	input(N);
	solve(1, N, 1, N);
}

