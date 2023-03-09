#include <iostream>

using namespace std;

long long getNumberCount(long long n, int divisor)
{	
	long long count(0);
	
	for(long long i = divisor; i<= n; i*=divisor)
	{
		count += (n/i);
	}
	
	return count;
}

long long getMin(long long a, long long b)
{
	long long min;
	
	if(a < b)
		return a;
	else
		return b;
}


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n,m; 
	cin >> n >> m;
	
	long long n_2_count;
	long long n_5_count;
	
	n_2_count = getNumberCount(n, 2) - getNumberCount(m, 2) - getNumberCount(n-m, 2);
	n_5_count = getNumberCount(n, 5) - getNumberCount(m, 5) - getNumberCount(n-m, 5);

	cout << getMin(n_2_count, n_5_count) << endl;
	
	return 0;
}