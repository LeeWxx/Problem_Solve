#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;


void solve(string param)
{
	int result(0);
	
	for(int i= param.size()-1; i>=0;i--)
	{
		if(param[i] == '1')
		{
			result += pow(2, param.size() - (i+1));		
		}
	}
	
	cout << result;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input_str;
	getline(cin, input_str);

	
	int idx(0);
	
	int remainder = input_str.size() % 3;
	if(remainder != 0)
	{
		solve(input_str.substr(0, remainder));
		idx += remainder;
	}
	
	for(idx; idx < input_str.size(); idx += 3)
	{
		solve(input_str.substr(idx,3));	
	}
	
	cout << endl;
}