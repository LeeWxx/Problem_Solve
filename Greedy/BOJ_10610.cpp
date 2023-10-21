#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
	
int cnt_arr[10];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	bool ok = false;
	int sum = 0;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s.at(i) == '0')
			ok = true;
		
		sum += s.at(i) - '0';
		cnt_arr[s.at(i) - '0']++;
	}
	
	if(!ok || sum % 3 != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	
	string output;
	
	for(int i=9; i >= 0; i--)
	{
		for(int j=0; j<cnt_arr[i]; j++)
			output += i + '0';
	}

	cout << output << endl;
}