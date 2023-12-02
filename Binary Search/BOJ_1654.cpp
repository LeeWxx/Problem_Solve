#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getCount(vector<int> lanterns, long long len)
{
	int count(0);
	for(int i=0; i<lanterns.size(); i++)
	{
		count += lanterns[i] / len;
	}
	
	return count;
}

void input(vector<int>& lanterns, int K)
{
	for(int i=0; i<K; i++)
	{
		int x;
		cin >> x;
		lanterns.push_back(x);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int K, N;
	cin >> K >> N;

	vector<int> lanterns;	
	input(lanterns, K);
	
	long long left(1);
	long long right(INT_MAX);
	long long answer(0);
	
	while(left <= right)
	{
		long long  mid = left;
			mid += right;
		mid /= 2;
		
		int count = getCount(lanterns, mid);
		
		if(count < N)
			right = mid - 1;
		else
		{
			left = mid + 1;
			answer = max(answer, mid);
		}	
	}
	
	cout << answer << endl;
	
}






