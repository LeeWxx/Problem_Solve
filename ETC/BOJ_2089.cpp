#include <iostream>
#include <string>

using namespace std;


const int base_num = -2;

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input_num;
	cin >> input_num;
	
	int quotient(0);
	int remainder(0);
	
	string result;
	
	while(true)
	{	
		quotient = input_num / base_num;
		
		if(input_num % 2 != 0 && input_num < 0)
		{
			quotient ++;
			remainder = input_num - (base_num * quotient);
		}
		else
			remainder = input_num % base_num;
	
		result = to_string(remainder) + result;
		
		if(quotient == 0)
			break;	
		
		if(quotient == 1)
		{
			result = "1" + result;
			break;
		}
		else 
			input_num = quotient;
	}
	
	
	cout << result << endl;
}