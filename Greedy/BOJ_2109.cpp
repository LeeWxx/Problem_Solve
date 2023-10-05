#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT = 10000;

pair<int,int> lecture_arr[MAX_INPUT];
bool checked[MAX_INPUT];

bool desc(pair<int,int> a, pair<int,int> b){ 
  return a.first > b.first; 
} 

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int pay;
		cin >> pay;
		
		int day;
		cin >> day;
		
		lecture_arr[i] = make_pair(pay, day);
	}
	
	sort(lecture_arr, lecture_arr+n, desc);
	
	int sum(0);
	
	for(int i=0; i<n; i++)
	{
		int limit_day = lecture_arr[i].second;
		
		for(int j=limit_day-1; j>=0; j--)
		{
			if(checked[j] == false)
			{
				sum += lecture_arr[i].first;
				checked[j] = true;
				break;
			}
		}
	}
	
	cout << sum << endl;
	
	
 	return 0;
}