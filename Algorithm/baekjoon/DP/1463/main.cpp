#include <iostream>
#include <algorithm>
using namespace std;
int d[1000001];
int main()
{
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0)
		{
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if(i % 3 == 0)
		{
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}
	int min_cost = d[N];
	cout << min_cost << endl;
	return 0;
}