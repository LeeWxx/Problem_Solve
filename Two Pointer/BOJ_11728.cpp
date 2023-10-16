#include <iostream>

using namespace std;

const int MAX_INPUT = 1000000;

int first_arr[MAX_INPUT];
int second_arr[MAX_INPUT];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
		cin >> first_arr[i];

	for(int i=0; i<M; i++)
		cin >> second_arr[i];
	
	int first_idx(0);
	int second_idx(0);
	
	while(first_idx < N && second_idx < M)
	{
		if(first_arr[first_idx] < second_arr[second_idx])
			cout << first_arr[first_idx++] << " ";
		else
			cout << second_arr[second_idx++] << " ";
	}
	
	while(first_idx < N)
		cout << first_arr[first_idx++] << " ";
	
	while(second_idx < M)
		cout << second_arr[second_idx++] << " ";
}