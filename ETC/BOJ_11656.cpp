#include <iostream>
#include <cstring>

using namespace std;

const int MAX_INPUT_SIZE = 1000;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	char input_str[MAX_INPUT_SIZE+1];
	cin.getline(input_str, MAX_INPUT_SIZE+1);
	
	char *ptr = input_str;
	char **ptr_arr = new char*[strlen(input_str)];
	
	for(int i=0; i<strlen(input_str); i++)
	{
		ptr_arr[i] = ptr;
		ptr++;
	}
	
	int total = 0;
	int i = 0;
	while(i < strlen(input_str))
	{
		if(*(ptr_arr[i])!='\0')
		{
			i++;
			total ++;
		}
	}

	
	for(int i = total -1 ; i> 0; i--)
	{
		for(int j = 0; j<i; j++)
		{
			if(strcmp(ptr_arr[j], ptr_arr[j+1]) > 0)
			{
				char* temp = ptr_arr[j];
				ptr_arr[j] = ptr_arr[j+1];
				ptr_arr[j+1] = temp;
			}
		}
	}
	
	for(int i=0; i< total; i++)
	{
		cout << ptr_arr[i] << endl;
	}
	
	delete[] ptr_arr;	

	return 0;

}