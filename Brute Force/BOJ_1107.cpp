#include <iostream>
using namespace std;

const int BASE_CHANNEL = 100;
const int MAX_CHENNEL = 500000;
bool check(int check_num, int ban_num_arr[], int n)
{
	if(check_num == 0)
	{
		for(int i=0; i<n; i++)
		{
			if(ban_num_arr[i] == check_num)
				return false;
		}	
	}

		
	while(check_num != 0)
	{
		int remainder = check_num % 10;
		for(int i=0; i<n; i++)
		{
			if(ban_num_arr[i] == remainder)
				return false;
		}
		
		check_num /= 10;
	}
	
	return true;
}

int getNearBigNumber(int target_chanel, int ban_num_arr[], int n)
{
	int count(0);
	while(true)
	{
		if(check(target_chanel, ban_num_arr, n))
		{
			return count;	
		}
		target_chanel++;
		count++;
		
		if(count > MAX_CHENNEL)
			return count;
	}
	
	return count;
}

int getNearSmallNumber(int target_chanel, int ban_num_arr[], int n)
{	
	int count(0);
	while(target_chanel >= 0)
	{
		if(check(target_chanel, ban_num_arr, n))
			return count;	
		
		target_chanel--;
		count++;
	}
	
	if(target_chanel < 0)
		return MAX_CHENNEL+1;
	
	return count;
}

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int target_channel;
	cin >> target_channel;
	
	int ban_number_count;
	cin >> ban_number_count;
	
	int* ban_num_arr = new int[ban_number_count];
	
	for(int i=0; i<ban_number_count; i++)
		cin >> ban_num_arr[i];
	
	int plus_count = getNearSmallNumber(target_channel,ban_num_arr,ban_number_count);
	int minus_count = getNearBigNumber(target_channel,ban_num_arr,ban_number_count);
	
	int min_count = min(plus_count, minus_count);
	int first_move_channel;
	
	if(plus_count > minus_count)
		first_move_channel = target_channel + min_count;
	else 
		first_move_channel = target_channel - min_count;
	
	int btn_count(0);	
	
	if(first_move_channel == 0)
		btn_count++;
	
	while(first_move_channel != 0)
	{
		first_move_channel /= 10;
		btn_count++;
	}
	
	btn_count += min_count;
	
	int another_count = target_channel - BASE_CHANNEL;
	if(another_count < 0)
		another_count *= -1;
	
	if(btn_count > another_count)
		cout << another_count << endl;
	else
		cout << btn_count << endl;
}