#include <iostream>
#include <cmath>

using namespace std;

int charToInt(char ch)
{
	int result;
	
	if(ch >= 'A' && ch <= 'Z')
		result = ch - 'A' + 10;
	else 
		result = ch - '0';
	
	return result;
}

int main(int argc, char* argv[]) 
{
	string input_string;
	cin >> input_string;;
	
	int base;
	cin >> base;
	
	int result(0);
	
	for(int i = 0; i<input_string.size(); i++)
	{
		char ch = input_string[input_string.size() - (i+1)];
		result += pow(base, i) * charToInt(ch);
	}
	
	cout << result << endl;
	
}