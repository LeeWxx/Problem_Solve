#include <iostream>
#include <string>

using namespace std;

pair<long long, long long> getCoordinate(string& fragment_num, long long y, long long x, int idx, long long size)
{		
	if(idx == fragment_num.size())
		return make_pair(y, x);
	
	if(fragment_num[idx] == '1')
		return getCoordinate(fragment_num, y, x + size / 2, idx + 1, size / 2);
	else if(fragment_num[idx] == '2')
		return getCoordinate(fragment_num, y, x, idx + 1, size / 2);
	else if(fragment_num[idx] == '3')
		return getCoordinate(fragment_num, y + size / 2, x, idx + 1, size / 2);
	else
		return getCoordinate(fragment_num, y + size / 2, x + size / 2, idx + 1, size / 2);
	
	
}

string getFragmentNumber(long long tar_y, long long tar_x, long long y, long long x, long long size)
{
	if(size == 1) return "";
	
	if(x + size / 2 > tar_x && y + size / 2 > tar_y)
		return "2" + getFragmentNumber(tar_y, tar_x, y, x, size / 2);
	else if(x + size / 2 <= tar_x && y + size / 2 > tar_y)
		return "1" + getFragmentNumber(tar_y, tar_x, y, x + size / 2, size / 2);
	else if(x + size / 2 > tar_x && y + size / 2 <= tar_y)
		return "3" + getFragmentNumber(tar_y, tar_x, y + size / 2, x, size / 2);
	else
		return "4" + getFragmentNumber(tar_y, tar_x, y + size / 2, x + size / 2, size / 2);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	
	int d;
	string fragment_num; 
	
	cin >> d >> fragment_num;
	
	long long dx, dy;
	cin >> dx >> dy;
	
	long long size = ((1LL) << d);
	pair<long long, long long> coord = getCoordinate(fragment_num, 0, 0, 0, size);
	
	long long y = coord.first - dy; 
	long long x = coord.second + dx;

	if(0 <= y && y < size && 0 <= x && x < size)
		cout << getFragmentNumber(coord.first - dy, coord.second + dx, 0, 0, size);
	else
		cout << -1;
}






