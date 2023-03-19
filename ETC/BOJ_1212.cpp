#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void solve(string param)
{
	string result("");
	
	for(int idx = 0; idx < param.size(); idx++)
	{
		int number = param[idx] - '0';
		for(int i = 2; i>=0 ; i--)
		{
			int check_num = pow(2,i);

			if(number >= check_num)
			{
				result += '1';
				number -= check_num;
			}
			else
			{
				if(result != "")
					result += '0';
			}
		}	
	}
	
	if(result == "")
	{
		cout << 0;
		return;
	}

	cout << result;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input_str;
	getline(cin, input_str);

	
	solve(input_str);
	
	cout << endl;
	
}