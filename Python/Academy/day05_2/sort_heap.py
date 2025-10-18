# 힙 정렬(heap sort)
# 최대 힙으로 구성된 힙 트리를 기준으로 정렬을 하는 것을 의미한다.
# 이때 최대 힙이란, 가장 큰 값을 이진 트리의 루트 노드로 설정하고
# 자식노드의 값이 부모 노드의 값보다 항상 작거나 같은 상태를 유지하는 것을
# 최대 힙이라 한다.

# 최대 힙, 즉 가장 큰 값을 전체 트리에서 정렬된 값으로
# 빼내고, 남은 값들에 대해서
# 다시 최대 힙으로 정렬하여 이를 반복적으로 수행한다.

def heap_sort(arr):
  # 힙의 크기(길이)
  n = len(arr)

  # 최대 힙 구성
  for i in range(n // 2 - 1, -1, -1):
    # heapify 함수를 통해서 arr를 최대 힙 구성
    heapify(arr, n, i)
  print("최대힙: ", arr)

  # 힙에서 요소를 하나씩 꺼내어 정렬
  for i in range(n - 1, 0, -1):
    # 루트와 마지막 요소 교환
    arr[0], arr[i]= arr[i], arr[0]
    print(f"{i}. 힙 정렬: ", arr)
    # 루트에 대해 heapify 수행
    heapify(arr, i, 0)
  
  return arr


# 힙 정렬을 하기 위한 함수
def heapify(arr, n, i):
  # arr: 전체 트리
  # n: 현재 서브트리의 전체 크기
  # i: 현재 정렬하고자 하는 인덱스(서브트리의 루트 인덱스)
  largest = i # 가장 큰 값을 가진 인덱스에 대한 초기값
  left = 2 * i + 1 # 대상 노드의 왼쪽 자식 노드 인덱스
  right = 2 * i + 2 # 대상 노드의 오른쪽 자식 노드 인덱스

  # 왼쪽 자식이 루트보다 크면 largest를 왼쪽 자식으로 변경
  # (left < n) 이때 left의 인덱스는 힙 범위 이내여야 한다.
  if left < n and arr[left] > arr[largest]:
    largest = left
  
  # 오른쪽 자식이 현재 largest보다 크면 largest를 오른쪽 자식으로 변경
  if right < n and arr[right] > arr[largest]:
    largest = right
  
  # largest가 루트가 아니면 교환하고 재귀적으로 heapify 호출
  if largest != i:
    arr[i], arr[largest] = arr[largest], arr[i]
    heapify(arr, n, largest)

if __name__ == "__main__":
  arr = [3, 6, 8, 10, 1, 2, 1]
  print(heap_sort(arr)) # [1, 1, 2, 3, 6, 8, 10]