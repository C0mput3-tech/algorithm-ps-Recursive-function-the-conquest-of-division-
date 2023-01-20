#include<iostream>
#include<vector>
#include<algorithm>
#define time ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
int ch[4][2] = { 
	{1,0},
	{-1,0},
	{0,1},
	{0,-1} };
bool c[50][50] = { 0, };
int vv[50][50] = { 0, };
int ret = 0;
int m, n, k;
void reset() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			vv[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0;
		}
	}
}
void pr(int x,int y)
{
	
	c[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		
		int x2 =x+ ch[i][0];
		int y2 =y+ ch[i][1];
	
		if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n)
		{
			continue;
		}
		if (vv[x2][y2] == 1 && c[x2][y2] == 0)
		{

			pr(x2, y2);
		}
		
	}
}

int main()
{
	time;
	int t;
	cin >> t ;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		reset();
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			vv[x][y] = 1;
		}
		ret = 0;
		for (int xx=0; xx < m; xx++)
		{
			for (int yy = 0; yy < n; yy++)
			{
				if (vv[xx][yy] == 1 && c[xx][yy] == 0)
				{
					ret++;
					pr(xx, yy);
				}
			}
		}
		cout << ret << '\n';
		
	}


	return 0;
}
