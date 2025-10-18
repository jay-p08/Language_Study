# 깊이 우선 탐색( Depth - First - Search )
# 더 이상 자식 노드가 없는 가장 깊은 노드까지 방문한
# 가까운 부모 노드로 올라가 방문한 적이 없는 자식 노드
# 이를 반보갛ㄴ다.
# 이때 방문한지 여부를 set 자료구조를 통해
# 중복 방문을 가려낸다.

# 재귀를 통한 DFS 구현
def dfs_recursive( graph, start, visited = None ) :
    # visited가 None이면 새로운 set 생성( 최초 호출 시 )
    # if visited is None : visited = set() # 직관적인 방법
    visited = visited or set() # or의 성질을 이용한 방법

    # 현재 노드를 방문 처리
    visited.add( start )
    print( start, end = " " ) # 방문한 노드 출력

    # 현재 노드의 이웃 노드들을 탐색
    for next_node in graph[ start ] :
        # 아직 방문하지 않은 이웃 노드에 대해 재귀적으로 DFS 수행
        if next_node not in visited :
            # 이웃 노드가 방문한 적이 없다면
            dfs_recursive( graph, next_node, visited )

if __name__ == "__main__" :
    graph = {
    'A': ['B', 'C'],      # A는 B, C와 연결됨
    'B': ['A', 'D', 'E'], # B는 A, D, E와 연결됨
    'C': ['A', 'F'],      # C는 A, F와 연결됨
    'D': ['B'],           # D는 B와 연결됨
    'E': ['B', 'F'],      # E는 B, F와 연결됨
    'F': ['C', 'E']       # F는 C, E와 연결됨
    }

    print( "재귀적 DFS : " )
    dfs_recursive( graph, "A" )