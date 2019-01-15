## Topological sort ( 위상 정렬 )

DAG(Directed Acyclic Graph)에서 방향성을 거스르지 않게 정점을 나열한 것  
 * DAG : 사이클이 없는 방향 그래프
 
 ### Description
 
 1. Using DFS  
 ```
 DFS가 끝나는 순으로 stack에 push.
 모든 탐색이 끝나면 stack에서 pop한 순서가 위상정렬된 순서다.
 ```
 2. Using indegree
  * indegree : 한 정점에서 자신에게 돌아오는 방향인 간선의 수
  ```
  1) indegree 수를 카운트한다.
  2) queue에 indegree가 0인 정점을 push.
  3) queue가 empty일 때까지 다음을 반복
     front에 있는 정점을 pop하고 그 정점에서 나가는 간선을 지운다.(indegree-1)
     그 중 indegree가 0인 정점을 queue에 push.
  4) 위 3)단계에서 pop한 순이 위상정렬된 순서다.
  ```
