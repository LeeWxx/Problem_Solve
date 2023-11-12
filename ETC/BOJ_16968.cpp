#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_COUNT = 26;
const int NUMBER_COUNT = 10;

int getCount(string str)
{
	char pre = '.';
	
	int count(1);
	
	for(int i=0; i<str.size(); i++)
	{
		int minus;
		
		if(str[i] == pre)
			minus = 1;
		else
			minus = 0;
		
		if(str[i] == 'd')
			count *= (NUMBER_COUNT - minus);
		else if(str[i] == 'c')
			count *= (ALPHABET_COUNT - minus);
		
		pre = str[i];
	}
	
	return count;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input;
	cin >> input;
	
	cout << getCount(input);
}



