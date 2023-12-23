#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n)
{
	if(n == 1 || n == 0)
		return 1;
	
	return factorial(n-1) * n; 
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	vector<int> v;
	for(int i=1; i<=N; i++)
		v.push_back(i);
	
	int n;
	cin >> n;
	
	if(n == 1)
	{
		long long k;
		cin >> k;
		
		k -= 1;
		
		while(N > 0)
		{	
			long fac = factorial(N-1);
	
			long quotient = k / fac;
			long remainder = k % fac;	
		
			cout << v[quotient] << " ";
			v.erase(v.begin() + quotient);
			k = remainder;
			N -= 1;
		}		 
		
		cout << "\n";
	}
	else
	{
		long long cnt = 0;
	
		while(N > 0)
		{
			long long num;
			cin >> num;
	
			int idx = (int)(find(v.begin(), v.end(), num)- v.begin()); 
			cnt += idx * factorial(N - 1);
			v.erase(v.begin() + idx);
		
			N-=1;
		}	
	
		cout << cnt + 1 << "\n";	
	}
}