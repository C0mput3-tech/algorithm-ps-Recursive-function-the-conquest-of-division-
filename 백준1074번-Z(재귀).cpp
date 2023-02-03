#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int ss=0;
int xx, yy;
#define time ios::sync_with_stdio(0),cin.tie(0);
/*
void qd(int x, int y, int size)
{
	int h = size/2;
	if (x == xx && yy == y)
	{
		cout<<ss;
		return;
	}
	else if (size <= 1)
	{
		ss++;
		return;
	}
				 qd( x , y, h);
				 qd( x + h, y, h);
				 qd( x, h, h);
				 qd( x + h, y + h, h);					
}
*/
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
		//cout << "xxxx" << x << " ";
		x -= h;
		ss++;
	}
	if (y >= h)
	{
		//cout << "yyyyy" << y << " ";
		y -= h;
		ss += 2;
	}
	//cout << "\n";
	//cout << "size" << ss * size*2 << " \n";
	return ss*h*h+qd(x, y, h);
}
int main() {
	time;
	int k,sum=1,kc;
	//cout << "gg";
	cin >> k>>yy>>xx;
	kc = k;
	while (k--)
	{
		sum *= 2;
	}
	//cout << "sum" << sum << '\n';
	cout<<qd (xx, yy, sum);
	return 0;
}
