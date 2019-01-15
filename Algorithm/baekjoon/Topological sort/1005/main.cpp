#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
int indegree[1001];
int cost[1001];
int d[1001];
queue<int> q;
int main()
{
	int t, n, k, x, y, w;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		v.resize(n + 1);
		for (int i = 1; i <= n; i ++)
		{
			cin >> cost[i];
			d[i] = cost[i];
		}
		while(k--)
		{
			cin >> x >> y;
			v[x].push_back(y); // graph
			++indegree[y]; 
		}
		for (int i = 1; i <=n; i++)
		{
			if (!indegree[i]) q.push(i);
		}
		while(!q.empty())
		{	
			int node = q.front();
			q.pop();
			for (auto next : v[node])
			{
				indegree[next]--;
				if (!indegree[next]) q.push(next);
				d[next] = max(d[next], d[node] + cost[next]);
			}
		}
		cin >> w;
		cout << d[w] << endl;
		v.clear(); // vector ºñ¿ì±â
	}
	return 0;
}