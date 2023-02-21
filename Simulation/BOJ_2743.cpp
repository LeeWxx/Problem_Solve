#include <iostream>

using namespace std;


const int MAX_INPUT_LENGTH = 100;
int my_strlen(char* str)
{
	char* temp(str);
	int count(0);
	
	while(true)
	{
		temp = str+count;
		
		if(*temp == '\0')
			return count;
		count++;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	char str[MAX_INPUT_LENGTH+1];
	cin.getline(str,MAX_INPUT_LENGTH+1);
	
	int length = my_strlen(str);
	
	cout << length << endl;
}