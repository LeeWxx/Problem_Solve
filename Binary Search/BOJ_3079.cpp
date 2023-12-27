#include <iostream>
#include <limits.h>
using namespace std;

const long long MAX_T = 1000000000;
const long long MAX_M = 1000000000;
const int MAX_N = 100000;

int t_arr[MAX_N];

long long safety_add(long long num1, long long num2) 
{ 
    if (num1 > LONG_LONG_MAX - num2) 
	{
		cout << "over flow" << "\n";
		return -1;
	}
    else
        return num1 + num2; 
} 

bool check(int N, int M, long long check_time)
{
	long long cnt = 0;
	
	for(int i=0; i<N; i++)
	{
		cnt = safety_add(check_time / t_arr[i], cnt); 
		if(cnt >= M)
			return true;
	}

	return false;
}

long long binarySearch(int N, int M)
{
	long long low = 1;
	long long high = MAX_T * MAX_M;
	
	long long ret;
	
	while(low <= high)
	{
		long long mid = (low + high) / 2;
		
		if(check(N, M, mid))
		{
			ret = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	return ret;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
		cin >> t_arr[i];
	
	
	cout << binarySearch(N, M) << "\n";
}