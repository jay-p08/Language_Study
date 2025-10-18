# 이진 트리
# 데이터를 담고 있는 노드를 기준으로
# 좌우 자식 노드의 주소를 노드가 담게 된다.
# 이러한 노드를 이진트리라는 클래스의 root로 설정하여
# 트리 모양의 이진 트리 구조를 만들 수 있게 된다.

# 노드를 정의할 클래스
class Node:
  def __init__(self, data):
    self.data = data
    # left와 right는
    # 각각 왼쪽 자식 노드의 주소와
    # 오른쪽 자식 노드의 주소를 담게 된다.
    self.left:Node = None
    self.right:Node = None

# 이진 트리 구조를 담당할 BinaryTree 클래스
class BinaryTree:
  def __init__(self):
    # 루트 노드: 트리의 최상위 노드
    self.root = None
  
  # 트리에 데이터 삽입
  def insert(self, data):
    # 만약 루트에 저장된 노드가 없다면
    if not self.root:
      # 전달된 데이터를 노드에 담아서 루트로 설정
      self.root = Node(data)
      return
    
    queue = [self.root]

    # 대기열(queue)가 남아 있는 동안 반복
    while queue:
      # 현재 대기열의 대상 노드
      node = queue.pop(0)

      if not node.left: # 대상 노드의 왼쪽 자식 노드가 없다면
        node.left = Node(data) # 자식 노드를 만들어서 데이터를 삽입
        return
      
      # 오른쪽 자식 노드에도 동일하게 반복
      if not node.right:
        node.right = Node(data)
        return
      # 만약 양쪽 자식 노드가 모두 존재한다면
      # 대기열 대상 노드에 양쪽 자식 노드를 추가하여
      # 자식노드에 대해서 동일한 로직 수행
      queue.append(node.left)
      queue.append(node.right)

# 전위 순회(Preorder Traversal)
def preorder(node):
  if node: # 전달된 node에 주소값이 있다면
    print(node.data, end=" ") # 노드의 데이터를 출력
    preorder(node.left) # 왼쪽 자식 노드에 반복
    preorder(node.right)# 오른쪽 자식 노드에 반복

# 중위 순회(Inorder Traversal)
def inorder(node):
  if node:
    inorder(node.left)
    print(node.data, end=" ")
    inorder(node.right)

# 후위 순회(Postorder Traversal)
def postorder(node):
  if node:
    postorder(node.left)
    postorder(node.right)
    print(node.data, end=" ")

if __name__ == "__main__" :
  tree = BinaryTree()
  for x in range( 1, 8 ) :
    tree.insert( x )
print( "전위 순회 : " )
preorder( tree.root )

print( "\n중위 순회 : " )
inorder( tree.root )

print( "\n후위 순회 : " )
postorder( tree.root)
