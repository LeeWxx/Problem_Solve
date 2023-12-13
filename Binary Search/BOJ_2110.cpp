#include <iostream>

using namespace std;

const int MAX_SIZE = 200000;

int coord_arr[MAX_SIZE+1];
int copy_arr[MAX_SIZE+1];

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int l_idx = left;
	int r_idx = mid + 1;
	
	int copy_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(coord_arr[l_idx] < coord_arr[r_idx])
			copy_arr[copy_idx++] = coord_arr[l_idx++];
		else
			copy_arr[copy_idx++] = coord_arr[r_idx++];
	}
	
	while(l_idx <= mid)
		copy_arr[copy_idx++] = coord_arr[l_idx++];
	
	while(r_idx <= right)
		copy_arr[copy_idx++] = coord_arr[r_idx++];
	
	for(int i=left; i<=right; i++)
		coord_arr[i] = copy_arr[i];
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


int getCount(int N, int length)
{
	int cnt(1);
	int last_coord = coord_arr[1];
	
	for(int i=2; i<=N; i++)
	{
		if(coord_arr[i] >= last_coord + length)
		{
			cnt++;
			last_coord = coord_arr[i];
		}
	}
	
	return cnt;
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int N, C;
	cin >> N >> C;
	
	int left = 0;
	int right = 0;
	
	for(int i=1; i<=N; i++)
	{
		int x;
		cin >> x;
		coord_arr[i] = x;
		
		if(x > right)
			right = x;
	}
	
	mergeSort(1, N);

	int ans(0);
	while(left <= right)
	{
		int mid = (left + right) / 2;
		
		if(getCount(N, mid) >= C)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
	
	cout << ans << "\n";
}






