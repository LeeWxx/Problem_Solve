#include <iostream>

using namespace std;
const int MAX_INPUT = 500000;

int input[MAX_INPUT+1];
int copy_arr[MAX_INPUT+1];

void merge(int left, int right, long long& cnt)
{
	int mid = (left + right) / 2;
	int l_idx = left;
	int r_idx = mid + 1;
	
	int copy_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(input[l_idx] > input[r_idx])
		{
			cnt += mid - l_idx + 1;		
			copy_arr[copy_idx++] = input[r_idx++];
		}
		else
			copy_arr[copy_idx++] = input[l_idx++];
	}
	
	while(l_idx <= mid)
	{
		copy_arr[copy_idx++] = input[l_idx++];
	}
	
	while(r_idx <= right)
	{
		copy_arr[copy_idx++] = input[r_idx++];
	}
	
	for(int i=left; i<=right; i++)
		input[i] = copy_arr[i];
	
}

void mergeSort(int left, int right, long long& cnt)
{
	if(left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergeSort(left, mid, cnt);
	mergeSort(mid + 1, right, cnt);
	merge(left, right, cnt);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++)
		cin >> input[i];
	
	long long cnt(0);
	mergeSort(1, N, cnt);
	
	cout << cnt << "\n";	
}





