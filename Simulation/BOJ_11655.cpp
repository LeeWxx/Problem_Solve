#include <iostream>
#include <string>

using namespace std;


char ROT13(char ch)
{
	if(ch == ' ')
		return ch;
	else if(isdigit(ch))
		return ch;
	else
		for(int i = 0; i<13; i++)
		{
			if(ch == 'z')
				ch = 'a';
			else if(ch == 'Z')
				ch = 'A';
			else 
				ch++;
		}	
	return ch;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input_string;
	getline(cin, input_string);

	string output_string("");
	
	for(char ch : input_string)
		output_string += ROT13(ch);
	
	cout << output_string << endl;
	
	return 0;

}