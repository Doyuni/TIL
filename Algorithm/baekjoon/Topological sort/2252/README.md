# 줄 세우기
Using _DFS_

## C++
```c++
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int visited[32001];
vector<vector<int>> v;
stack<int> s;
void dfs(int n)
{
	visited[n] = true;
	for (auto node : v[n])
	{
		if (visited[node]) continue;
		dfs(node);
	}
	s.push(n); //더 이상 탐색할 곳이 없을 때 push
}
int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	while (m--)
	{
		scanf("%d %d", &a, &b); 
		v[a].push_back(b); // graph
	}
	for (int i = 1; i <= n; i++)
	{
		if(!visited[i]) dfs(i);
	}
	while(!s.empty()){ 
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}
```
