#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_INPUT_SIZE = 3000000;
const int input_count = 4;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long result(0);
	
	for(int i=0; i<input_count/2; i++)
	{
		char first_input[MAX_INPUT_SIZE];
		char second_input[MAX_INPUT_SIZE];
		
		cin >> first_input; 
		cin >> second_input;
	
		char *first_ptr  = first_input;
		char *second_ptr  = second_input;
	
		while(*first_ptr)
    	{
        	first_ptr++;
    	}
	
		while(*second_ptr)
		{
			*first_ptr = *second_ptr;
			second_ptr++;
			first_ptr++;
		}
		
		*first_ptr = '\0';
		result += atoll(first_input);
	}
	
	cout << result << endl;
}