#include <iostream>

using namespace std;

const int MAX_INPUT = 20;

bool sum_checked[2000000];

int set[MAX_INPUT+1];
int output[MAX_INPUT+1];
int checked[MAX_INPUT+1];

void check(int N)
{
	int sum(0);
	
	for(int i=0; i<N; i++)
		sum += output[i];
	
	sum_checked[sum] = true;
}

void go(int idx, int target_idx, int N, int start_idx)
{
	if(idx == target_idx)
		check(target_idx);
	
	for(int i=start_idx; i<N; i++)
	{
		if(checked[i])
			continue;
		
		output[idx] = set[i];
		checked[i] = true;
		
		go(idx+1, target_idx, N, i+1);
		
		checked[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
		cin >> set[i];
	
	
	for(int i=1; i<=N; i++)
	{
		go(0, i, N, 0);
	}
	
	for(int i=1; i<=2000000; i++)
	{
		if(sum_checked[i] == false)
		{
			cout << i << endl;
			break;
		}
	}
}