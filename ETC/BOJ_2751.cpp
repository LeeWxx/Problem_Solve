#include <iostream>

using namespace std;

const int MAX_INPUT = 1000000;

int input[MAX_INPUT+1];
int temp_sort_arr[MAX_INPUT+1];

void Input(int N)
{
	for(int i=1; i<=N; i++)
		cin >> input[i];
}

void merge(int left, int mid, int right)
{
	int l_idx = left;
	int r_idx = mid + 1;
	
	int s_idx = left;
	
	while(l_idx <= mid && r_idx <= right)
	{
		if(input[l_idx] > input[r_idx])
			temp_sort_arr[s_idx++] = input[r_idx++];
		else
			temp_sort_arr[s_idx++] = input[l_idx++];
	}
	
	while(l_idx <= mid)
		temp_sort_arr[s_idx++] = input[l_idx++];
	
	while(r_idx <= right)
		temp_sort_arr[s_idx++] = input[r_idx++];
	
	int size = right - left + 1;
	for(int i=0; i<size; i++)
	{
		input[left+i] = temp_sort_arr[left+i];
	}
	
}


void mergeSort(int left, int right)
{
	if(left >= right)
		return;
	int mid = (left + right) / 2;
	
	mergeSort(left, mid);
	mergeSort(mid+1, right);
	merge(left, mid, right);
}

void print(int N)
{
	for(int i=1; i<=N; i++)
		cout << input[i] << "\n";
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	Input(N);
	mergeSort(1, N);
	
	print(N);
}



