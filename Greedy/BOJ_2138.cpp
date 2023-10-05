#include <iostream>
#include <string>

using namespace std;

const int MAX_INPUT = 100000;

int on_state[MAX_INPUT+1];
int off_state[MAX_INPUT+1];
int target[MAX_INPUT+1];

void onOff(int* arr, int idx, int N)
{
	for(int i=-1; i<=1; i++)
	{
		if(idx == 1 && i == -1)
			continue;
		
		if(idx == N && i == 1)
			continue;
		
		arr[idx + i] = !arr[idx + i];
	}
}

void input(int N)
{
	string s1;
	string s2;
	
	cin >> s1;
	for(int i=1; i<=N; i++)
	{
		off_state[i] = s1.at(i-1) - '0';
		on_state[i] = s1.at(i-1) - '0';
	}
	
	cin >> s2;
	for(int i=1; i<=N; i++)
	{
		target[i] = s2.at(i-1) - '0';
	}
	
	onOff(on_state, 1, N);
}

int solve(int N)
{
	int on_state_cnt(1);
	int off_state_cnt(0);
	
	for(int i=2; i<=N; i++)
	{
		if(target[i-1] != on_state[i-1])
		{
			on_state_cnt++;
			onOff(on_state, i, N);
		}
		
		if(target[i-1] != off_state[i-1])
 		{
 			off_state_cnt++;
 			onOff(off_state, i, N);
 		}
	}
	
	if(target[N] != on_state[N])
		on_state_cnt = N+1;
	if(target[N] != off_state[N])
		off_state_cnt = N+1;
	
	int result = min(on_state_cnt, off_state_cnt);
	
	if(result == N+1)
		return -1;
	else
		return result;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	input(N);
	
	cout << solve(N) << endl;
}