#include <iostream>
#include <algorithm>
using namespace std;
int t[500][500];
int d[500][500];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
		{
			cin >> t[i][j];
		}
	}
	d[0][0] = t[0][0];
	for (int k = 1; k < n; k++)
	{
		for (int h = 0; h < n; h++)
		{
			if (h == 0)
			{
				d[k][0] = d[k - 1][0] + t[k][0]; //�ٷ� ���� �ִ��θ� ������ �� ����.
			}
			else if (k == h)
			{
				d[k][h] = d[k - 1][h - 1] + t[k][h]; // �ٷ� �� ������ �ִ��θ� ������ �� ����.
			}
			else {
				d[k][h] = max(d[k - 1][h - 1], d[k - 1][h]) + t[k][h];
			}
		}
	}
	int max_cost = 0; // 0���� ���� �� ����.
	for (int index = 0; index < n; index++)
	{
		max_cost = max(d[n - 1][index], max_cost);
	}
	cout << max_cost << endl;
	return 0;
}