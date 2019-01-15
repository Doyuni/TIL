# ACM craft
상당히 까다로웠던 문제(문제의 조건을 꼼꼼히 봐야 풀 수 있다.)  

ex) 건물 순서는 정해져 있지 않음, 건물을 짓는데 0초가 걸릴 수 있음 ( 아래 test case가 아주 좋은 예제다.)

Using _Indegree_
## C++
```c++
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
		v.clear(); // vector 비우기
	}
	return 0;
}
```

**_input_**
```
1
10 11
10 20 30 40 50 60 70 80 90 100
1 2
2 3
3 6
6 9
5 4
4 7
7 8
8 9
4 9
10 7
4 3
9
```
**_output_**
```
340
```
