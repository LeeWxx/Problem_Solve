#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_SIZE = 100000;

long long cards[MAX_SIZE+1];
long long copy_arr[MAX_SIZE+1];

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int l_idx = left;
	int r_idx = mid + 1;
	
	int copy_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(cards[l_idx] < cards[r_idx])
			copy_arr[copy_idx++] = cards[l_idx++];
		else
			copy_arr[copy_idx++] = cards[r_idx++];
	}
	
	while(l_idx <= mid)
		copy_arr[copy_idx++] = cards[l_idx++];
	
	while(r_idx <= right)
		copy_arr[copy_idx++] = cards[r_idx++];
	
	for(int i=left; i<=right; i++)
		cards[i] = copy_arr[i];
}

void mergeSort(int left, int right)
{
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, right);
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++)
	{
		long long x;
		cin >> x;
		cards[i] = x;
	}
	
	mergeSort(1, N);
	int max_cnt(1);
	long long max_val(cards[1]);

 	
	int cnt(1);
	for(int i=1; i<=N; i++)
	{
		if(i < N && cards[i] == cards[i+1])
			cnt++;
		else
		{
			if(max_cnt < cnt)
			{
				max_val = cards[i];
				max_cnt = cnt;
			}
			cnt = 1;
		}
	}
	
	cout << max_val << endl; 
}






