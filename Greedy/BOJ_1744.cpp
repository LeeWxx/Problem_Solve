#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N; 
	cin >> N;
	
	vector<int> positive_vec;
	vector<int> negative_vec;
	
	int one_cnt(0);
	
	for(int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		
		if(x <= 0)
			negative_vec.push_back(x);
		else if(x != 1)
			positive_vec.push_back(x);
		else
			one_cnt++;
	}
	
	sort(negative_vec.begin(), negative_vec.end());
	
	sort(positive_vec.begin(), positive_vec.end());
	reverse(positive_vec.begin(), positive_vec.end());
	
	int sum(0);
	
	int n_size = negative_vec.size();
	for(int i=0; i<n_size; i+=2)
	{
		if(i+1 < n_size)
			sum += (negative_vec[i] * negative_vec[i+1]);
	}
	
	
	if(n_size % 2 != 0)
		sum += negative_vec[n_size-1];
	
	int p_size = positive_vec.size();
	for(int i=0; i<p_size; i+=2)
	{
		if(i+1 < p_size)
			sum += (positive_vec[i] * positive_vec[i+1]);
	}
	
	if(p_size % 2 != 0)
		sum += positive_vec[p_size-1];
						
	sum += one_cnt;
	
	cout << sum << endl;
}