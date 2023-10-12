#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_INPUT = 50;

vector<int> num_vec;
vector<char> symbol_vec;

int solve()
{
	int sum(num_vec[0]);
	
	bool m_brac_open = false;
	for(int i=1; i<num_vec.size(); i++)
	{
		if(symbol_vec[i-1] == '+' && !m_brac_open)
			sum += num_vec[i];
		else
		{
			m_brac_open = true;
			sum -= num_vec[i];
		}
			
	}
	
	return sum;
}

void parse(string s)
{
	s += '.';
	
	string temp("");
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] != '+' && s[i] != '-' && s[i] != '.')
		{
			temp += s[i];
		}
		else
		{
			symbol_vec.push_back(s[i]);
			num_vec.push_back(stoi(temp));
			temp = "";
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	parse(s);
	cout << solve() << "\n";

 	return 0;
}