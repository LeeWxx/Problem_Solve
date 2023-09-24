#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_INPUT = 100;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	pair<int, int>* conference_arr = new pair<int, int>[N];
	
	for(int i=0; i<N; i++)
	{
		cin >> conference_arr[i].second >> conference_arr[i].first;
	}
	
	sort(conference_arr, conference_arr + N);
	
	int last_hour(0);
	int idx(0);
	int cnt(0);
	
	while(idx < N) 
	{
		if(conference_arr[idx].second >= last_hour)
		{
			last_hour = conference_arr[idx].first;
			cnt++;
		}
		
		idx++;
	}
	
	cout << cnt << endl;
	
 	return 0;
}