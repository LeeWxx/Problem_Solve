#include <iostream>
#include <string.h>

using namespace std;

const int MAX_SIZE = 100;
const int MAX_SUM = 20;

long cache[MAX_SIZE][MAX_SUM+1];
int arr[MAX_SIZE];

long solve(int idx, int sum, int N)
{
	
	if(sum > 20 || sum < 0)
		return 0;
	
	if(idx == N-1)
	{
		if(sum == arr[N-1])
			return 1;
		else
			return 0;
	}
	
	if(cache[idx][sum] != -1)
		return cache[idx][sum];
	
	long ret;
	
	ret = solve(idx + 1, sum + arr[idx], N) + solve(idx + 1, sum - arr[idx], N);
	cache[idx][sum] = ret;
	return ret;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(cache, -1, sizeof(cache));
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> arr[i];
	}
	
	cout << solve(1, arr[0], N) << "\n";
}