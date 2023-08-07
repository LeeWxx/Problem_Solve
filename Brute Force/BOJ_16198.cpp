#include <iostream>
#include <vector>

using namespace std;
const int MAX_INPUT = 10;

int excute_arr[MAX_INPUT-2];
vector<int> input_vec;

int excute(int N)
{
	int sum(0);
	vector<int> temp_vec(input_vec);
	
	for(int i=0; i<N; i++)
	{
		int idx = excute_arr[i];
		sum += (temp_vec.at(idx-1) * temp_vec.at(idx+1));
		temp_vec.erase(temp_vec.begin() + idx);
	}
		
	return sum;
}

void go(int idx, int target_idx, int N, int& result)
{
	if(idx == target_idx)
	{
		result = max(result, excute(target_idx));	
	}
	
	for(int i=1; i<N-1; i++)
	{
		excute_arr[idx] = i;
		go(idx+1, target_idx, N-1, result);	
	}
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
		input_vec.push_back(x);
	}
	
	int result(0);
	
	go(0, N-2, N, result);
	
	cout << result << endl;
}