#include <iostream>
#include <algorithm>

using namespace std;

const char vowel_arr[5] = {'a', 'e', 'i', 'o', 'u'};

char output_arr[15];
bool check_arr[15] {false, };

void print(int L)
{
	int vowel_count(0);
	
	for(int i=0; i<L; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(output_arr[i] == vowel_arr[j])
			{
				vowel_count++;
				break;
			}
		}
	}
	
	if(vowel_count < 1 || L-vowel_count < 2)
		return;
	
	for(int i=0; i<L-1; i++)
		cout << output_arr[i];
	
	cout << output_arr[L-1] << "\n";
}

void solve(int idx, int L, char* input_arr, int C, int last_idx)
{
	if(idx == L)
	{
		print(L);
		return;
	}
	
	for(int i=last_idx; i<C; i++)
	{
		if(check_arr[i])
			continue;
		
		output_arr[idx] = input_arr[i];
		check_arr[i] = true;
		
		solve(idx+1, L, input_arr, C, i);
		
		check_arr[i] = false;
	}
}


int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int L,C;
	cin >> L >> C;
	
	char* input_arr = new char[C];
	
	for(int i=0; i<C; i++)
		cin >> input_arr[i];
	
	sort(input_arr, input_arr+C);
	
	solve(0, L, input_arr, C, 0);
	
	delete[] input_arr;
}