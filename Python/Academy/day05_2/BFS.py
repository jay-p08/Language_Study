# 너비 우선 탐색(Breadth-First-Search)
# 같은 레벨에 있는 정점(노드)들을
# 우선적으로 탐색하는 알고리즘이다.
# queue를 사용하여 구현
# 시작 정점(노드)로부터 가까운 정점을 먼저 방문하고
# 멀리 떨어져 있는 정점을 나중에 방문

# collections 모듈에 있는 deque(양방향 큐) 자료구조 임포트
from collections import deque

# BFS 구현
def bfs(graph, start):

  # 방문한 노드를 저장할 set 자료구조 초기화
  visited = set()

  # 시작 노드를 포함한 queue 생성
  queue = deque([start])

  # 시작 노드를 방문 처리
  visited.add(start)
  
  # 큐가 빌 때까지 반복
  while queue:
    # 큐에서 가장 왼쪽 노드를 꺼냄(선입선출)
    vertex = queue.popleft()

    # 현재 방문 중인 노드 출력(공백으로 구분)
    print(vertex, end=" ")

    # 현재 노드의 이웃 노드들을 순회
    for neighbor in graph[vertex]:
      # 아직 방문하지 않은 이웃 노드에 대해
      if neighbor not in visited:
        # 방문 처리
        visited.add(neighbor)
        # 큐의 오른쪽에 이웃 노드 추가
        queue.append(neighbor)

if __name__ == "__main__":
  graph = {
    'A': ['B', 'C'],      # A는 B, C와 연결됨
    'B': ['A', 'D', 'E'], # B는 A, D, E와 연결됨
    'C': ['A', 'F'],      # C는 A, F와 연결됨
    'D': ['B'],           # D는 B와 연결됨
    'E': ['B', 'F'],      # E는 B, F와 연결됨
    'F': ['C', 'E']       # F는 C, E와 연결됨
  }
  print("BFS:")
  bfs(graph, 'A')