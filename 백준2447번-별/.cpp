#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int si;
bool b[2200][2200];
int xx, yy;
#define time ios::sync_with_stdio(0),cin.tie(0);
void z(int x, int y, int sp)
{
	if (sp == 1)
		return;
	int h = sp / 3;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			b[y + h + i][x + h + j] = 1;
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		z(x + i * h, y,h);
	}
	z(x + 0 * h, y + h, h);
	z(x + h * 2, y + h, h);


	for (int i = 0; i < 3; i++)
	{
		z(x + i * h, y+h*2, h);
	}
	
}
int main() {
	time;
	cin >> si;
	z(0, 0, si);
	for (int i = 0; i < si; i++)
	{
		for (int j = 0; j < si; j++)
		{
			if (b[i][j] == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}
	return 0;
}
