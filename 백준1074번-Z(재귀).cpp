#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int ss=0;
int xx, yy;
#define time ios::sync_with_stdio(0),cin.tie(0);
int a[2][2] = {
	{0,1},
	{2,3}
};
int qd(int x, int y, int size)
{
	int h = size / 2;
	ss = 0;
	if (x<2&&y<2)
	{
		return a[y][x];
	}
	if(x>=h)
	{
		x -= h;
		ss++;
	}
	if (y >= h)
	{
		y -= h;
		ss += 2;
	}
	return ss*h*h+qd(x, y, h);
}
int main() {
	time;
	int k,sum=1;
	cin >> k>>yy>>xx;
	while (k--)
	{
		sum *= 2;
	}
	cout<<qd (xx, yy, sum);
	return 0;
}
