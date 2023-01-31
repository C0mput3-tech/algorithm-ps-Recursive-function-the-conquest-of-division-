#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int ss;
#define time ios::sync_with_stdio(0),cin.tie(0);

string qd(string it[100], int x, int y, int size)
{
	bool t = true;
	char c = it[y][x];
	if (size <= 1)
	{
		return string(1,c);
	}
	string ul;
	string ur;
	string dl;
	string dr;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (c != it[y + i][x + j])
				{
					ul = qd(it, x , y, size / 2);
					ur = qd(it, x + size / 2, y, size / 2);
					dl = qd(it, x, y + size / 2, size / 2);
					dr = qd(it, x + size / 2, y + size / 2, size / 2);
					t = false;
					break;
					
				}
			}
			if (t==false)
			{
				break;
			}
	}
		if (t == true)
		{
			return string(1, c);
	}
		return string("(") + ul + ur + dl + dr + string(")");
}

int main() {
	string ss[100];
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> ss[i];
	}
	cout << qd(ss, 0, 0, k);
	return 0;
}
