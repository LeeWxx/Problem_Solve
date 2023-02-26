#include <iostream>
#include <string>

using namespace std;

const int TOTAL_ALPHABET_COUNT = 26;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int output_arr[TOTAL_ALPHABET_COUNT] = { };
	
	for(int i =0; i< TOTAL_ALPHABET_COUNT ; i++)
		output_arr[i] = -1;
	
	string input_string;
	getline(cin, input_string);
	
	for(int i =0; i < input_string.size() ; i++)
	{
		int idx = input_string[i] - 'a';
		if(output_arr[idx] == -1)
			output_arr[idx] = i;
	}
	
	for(int i =0; i< TOTAL_ALPHABET_COUNT ; i++)
	{
		if(i != TOTAL_ALPHABET_COUNT - 1)
			cout << output_arr[i] << " ";
		else
			cout << output_arr[i] << endl;
	}
	
	return 0;

}