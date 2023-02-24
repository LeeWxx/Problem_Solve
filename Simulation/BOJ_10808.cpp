#include <iostream>
#include <string>

using namespace std;

const int TOTAL_ALPHABET_COUNT = 26;

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int alphabet_count_arr[TOTAL_ALPHABET_COUNT] = {0, };
	
	string input_string;
	getline(cin, input_string);
	
	for(int i =0; i< input_string.size() ; i++)
	{
		int idx = input_string[i] - 'a';
		alphabet_count_arr[idx]++;
	}
	
	for(int i =0; i< TOTAL_ALPHABET_COUNT ; i++)
	{
		if(i != TOTAL_ALPHABET_COUNT - 1)
			cout << alphabet_count_arr[i] << " ";
		else
			cout << alphabet_count_arr[i] << endl;
	}
	
	return 0;

}