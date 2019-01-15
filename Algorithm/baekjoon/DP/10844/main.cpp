#include <cstdio>
long long d[101][10];
int main()
{
	int n;
	const long long mod = 1000000000LL;
	scanf(" %d", &n);
	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j > 0) d[i][j] += d[i - 1][j - 1]; // 0�� ���� 1�� ����
			if (j < 9) d[i][j] += d[i - 1][j + 1]; // 9�� ���� 8�� ����
			//�̸� ���� ������ ��û���� ū ���� ���� ���� ����� �ٷ��� �� �Ѵ�.
			d[i][j] %= mod; // (A+B)%C = ((A%C)+(B%C))%C
		}
	}
	long long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += d[n][i];
	}
	printf("%lld\n", result % mod);
	return 0;
}