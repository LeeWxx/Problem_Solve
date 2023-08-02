#include <iostream>
#include <string>

using namespace std;

const int MAX_WORD_COUNT = 10;
const int MAX_ALPHABET_COUNT = 10;

int num_arr[MAX_ALPHABET_COUNT];
int order_arr[26];

string word_arr[MAX_WORD_COUNT];

int getNumber(string s)
{
	int sum(0);
	for(int i=0; i<s.length(); i++)
	{
		sum *= 10;
		sum += num_arr[order_arr[s.at(i) - 'A']];
	}
	
	return sum;
}

bool next(int N)
{		
	int first_idx(-1);
	
	for(int i=N-2; i>=0; i--)
	{
		if(num_arr[i] > num_arr[i+1])
		{
			first_idx = i;
			break;
		}
	}
	
	if(first_idx == -1)
		return false;
	
	for(int i=N-1; i>first_idx; i--)
	{
		if(num_arr[first_idx] > num_arr[i])
		{
			int temp = num_arr[i];
			num_arr[i] = num_arr[first_idx];
			num_arr[first_idx] = temp;
			
			break;
		}
	}
	
	int* temp = new int[N-(first_idx+1)];

	for(int i=first_idx+1; i<N; i++)
		temp[(N-1) - i] = num_arr[i];
		
	for(int i=first_idx+1; i<N; i++)
		num_arr[i] = temp[i - (first_idx+1)];
	
	delete[] temp;
	
	return true;
}

int solve(int N, int cnt)
{
	int sum(0);
	while(true)
	{
		int temp_sum(0);
		for(int i=0; i<N; i++)
		{
			temp_sum += getNumber(word_arr[i]);
		}
		
		sum = max(temp_sum, sum);
		
		if(!next(cnt))
			return sum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int alphabet_arr[26] = {0, };
	
	for(int i=0; i<N; i++)
	{
		cin >> word_arr[i];
		
		for(int j=0; j<word_arr[i].size();j++)
		{
			int idx = word_arr[i][j] - 'A';
			alphabet_arr[idx] += 1;
		}
	}
		
	int cnt(0);
	for(int i=0; i<26; i++)
	{
		if(alphabet_arr[i] != 0)
		{
			num_arr[cnt] = MAX_ALPHABET_COUNT - (cnt + 1);
			order_arr[i] = cnt;
			cnt++;
		}
	}
	
	cout << solve(N, cnt) << endl;
}