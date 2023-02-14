#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int k[6700][6700];
void r(int x, int y, int s,int ss)
{
	if (ss <= 1) {
		k[y][x] = 1;
		k[y + 1][x - 1] = 1;
		k[y + 1][x + 1] = 1;
		for (int i = 0; i < 5; i++)
		{
			k[y + 2][x - 2 + i] = 1;
		}
	}
	else
	{
		r(x, y, s / 2 - 1,ss/2);
		r(x - ((s / 2 - 1) / 2 + 1), y + ss * 3 / 2, s / 2 - 1, ss / 2);
		r(x + ((s / 2 - 1) / 2 + 1), y + ss * 3 / 2, s / 2 - 1, ss / 2);
	}
}
int n;
int main() {
	cin >> n;
	n /= 3;
	int n2 = n;
	int plus = n - 1;
	n *= 5;
	n += plus;
	n -= 1;
	r(n / 2, 0, n, n2);
	for (int i = 0; i < n2*3; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			if (k[i][j] == 1)
			{
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}