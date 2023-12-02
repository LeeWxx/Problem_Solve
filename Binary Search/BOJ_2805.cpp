#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long getLength(vector<int> trees, long long height)
{
	long long length(0);
	for(int i=0; i<trees.size(); i++)
	{
		if(trees[i] > height)
			length += (trees[i] - height);
	}
	
	return length;
}

void input(vector<int>& trees, int K)
{
	for(int i=0; i<K; i++)
	{
		int x;
		cin >> x;
		trees.push_back(x);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N, M;
	cin >> N >> M;

	vector<int> trees;	
	input(trees, N);
	
	long long left(0);
	long long right(2000000000);
	long long answer(0);
	
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		long long length = getLength(trees, mid);
		
		if(length < M)
			right = mid - 1;
		else
		{
			left = mid + 1;
			answer = max(answer, mid);
		}	
	}
	
	cout << answer << endl;
	
}







