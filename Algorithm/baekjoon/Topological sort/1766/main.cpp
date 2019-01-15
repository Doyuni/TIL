#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for using greater<int>
using namespace std;
vector<vector<int>> v;
int indegree[32001];
priority_queue<int, vector<int>, greater<int> > pq; // min heap
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	v.resize(n + 1);
	while (m--)
	{
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i]) pq.push(i);
	}
	while (!pq.empty())
	{
		int node = pq.top();
		pq.pop();
		cout << node << " ";
		for (auto e : v[node])
		{
			indegree[e]--;
			if (!indegree[e]) pq.push(e);
		}
	}
	return 0;
}