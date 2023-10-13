#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> card_vec;

int lower_bound (int num)
{	
	int l = 0;
	int r = card_vec.size();
	
	int mid;
	int ret;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(num == card_vec[mid])
		{
			ret = mid;
			r = mid - 1;
		}
		else if(num < card_vec[mid])
			r = mid-1;
		else
			l = mid+1;
	}
	
	return ret;
}

int upper_bound(int num)
{	
	int l = 0;
	int r = card_vec.size();
	
	int mid;
	int ret;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(num == card_vec[mid])  
		{
			ret = mid+1;
			l = mid+1;
		}
		else if(num < card_vec[mid])
			r = mid-1;
		else
			l = mid+1;
	}
	
	return ret;
}

int get_count(int num)
{
	return upper_bound(num) - lower_bound(num);
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		card_vec.push_back(x);
	}
	
	sort(card_vec.begin(), card_vec.end());
	
	int M;
	cin >> M;
	for(int i=0; i<M; i++)
	{
		int find;
		cin >> find;
		
		cout << get_count(find);
		
		if(i != M-1)
			cout << " ";
	}
}