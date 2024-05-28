# DataStructure_Algorithm
## 2024/05/14 Complete
* * *
## 자료 구조
### Linked List
* 정의: 구조체를 한 줄로 연결 시킨 데이터 구조
* 구성 요소
  * head: 연결 리스트에서 첫 번째 노드의 주소를 저장한 포인터
  * node: 연결 리스트 요소
  * value: 노드에 저장된 데이터
  * link: 다른 노드로 연결 위한 포인터
* Singly Linked List
  * 각 노드의 link에 다음 노드의 주소가 있다
  * 마지막 노드의 link는 NULL
    ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/db4c73da-84d5-4af5-aaaa-f7e849dd433b)
  * Code: [Singly Linked List](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day08/LinkedList.c)
* Doubly Linked List
  * 각 노드는 Llink와 Rlink를 가진 구조
  * 한쪽 링크는 선행, 다른 한 쪽 링크는 후속 노드를 가짐
  * 헤드 노드를 사용해 노드의 시작와 끝을 구분
  1. 헤드 노드가 리스트 일부인 경우
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/715a1c29-f8f8-423f-84d6-d9d0bc839781)
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/84c4d2fc-d4b6-4c35-97b3-9231abdc639b)
     - Code: [Doubly Linked List (1)](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day08/DoublyLinkedList.c)
  3. 헤드 노드가 리스트와 분리된 경우
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/cf578eeb-4c53-4514-890f-78691bf7a362)
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/2ee6707b-e9d0-430a-954b-be807923e305)
     - Code: [Doubly Linked List (2)](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day08/DoublyLinkedListwithHeader.c)

### Stack
* 성격: 가장 처음 쌓인 자료는 가장 나중에 나가는 자료, Last-In First-Out
* Stack in array
  - Code: [stack in array](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day10/Stack_array.c)
* Stack in list
  - Code: [stack in list](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day10/Stack_list.c)

### Queue
* 성격: 먼저 들어온 데이커가 먼저 나가는 자료구조, First-In First-Out
* Linear Queue
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/43763197-932e-476b-9471-790bcea2de9c)
  i.e.) Doouble-Ended Queue(deque)
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/59bdd8fc-2918-4444-8710-82d2c94a02e0)
  - Code: [Linear Queue in Linked List](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day11/Linear_Queue_LinkedList.c)
* Circular Queue
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/46bef5bf-57eb-4fa1-9222-3ede65ce2efe)
  - Code:    
    [Circular Queue in Linked List](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day11/Circular_Queue_LinkedList.c)    
    [Circular Queue in Array](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day11/Circular_Queue_Array.c)
* * *
## 정렬
### Bubble Sort
* 알고리즘: 인접한 레코드가 순서대로 되어 있지 않으면 교환, 전체가 정렬될 때까지 비교&교환의 반복
* 시간 복잡도: $`O(n^2)`$
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/05e93aaa-3bee-4d7a-80cb-4a7b0bdf106e)
* Code: [Bubble sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day13/bubble.c)
### Insertion Sort
* 알고리즘: 정렬되지 않은 숫자들 중에서 왼쪽부터 정렬할 값을 선택하여 값이 위치할 자리를 찾아 삽입하는 정렬(더 큰 값은 1칸씩 오른쪽으로 이동)
* 시간 복잡도: $`O(n^2)`$
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/067885fc-aeae-4783-96c1-00a7503cc145)
* Code: [Insertion sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day13/insertion.c)
### Shell Sort
* 알고리즘: 전체 리스트를 일정 간격의 부분 리스트로 나누고 부분 리스트를 정렬
* 시간 복잡도: $`O(n^{1.5})`$
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/4019438e-78f8-48b6-80fd-4ffe0902e4cc)
* Code: [Shell sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day13/shell.c)
### Merge Sort
* 집합을 두 개로 나누어, 각각을 정렬, 다시 하나로 합치는 방법
* 시간 복잡도: $`O(nlog_2(n))`$
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/1e02c6e7-e2bd-41b1-aa8f-b2ebeb310be1)
* Code: [Merge sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day14/Merge_Sort.c)
### Quick Sort
* low & high 교차할 때까지 반복, 교차점 기준으로 분할 --> 다시 퀵 정렬    
  최소 단위로 분할 될 때까지 반복
* 시간 복잡도: $`O(nlog_2(n))`$ (평균적으로 가장 빠름)
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/7328a98b-cd3f-4a22-a12b-23ede3cb6ef2)
* Code: [Quick sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day14/Quick_Sort.c)
### Bucket Sort
1. 단순히 자리수에 따라 버킷에 넣었다가 꺼내는 방법
   - 시간 복잡도: $`O(n)`$ (이론적인 하한선인 $`O(nlog_2(n))`$ 보다 작은 유일한 방법)
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/d2e59fe3-2e12-417e-85f6-231251ef3dd3)
   - Code: [Bucket sort](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day14/Bucket_Sort.c)
2. 2자리수 이상은 낮은 자리수로 먼저 분류한 다음,순서대로 읽어서 다시 높은 자리수로 분류하는 방법
   - 시간 복잡도: $`O(n)`$
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/50f5ca50-b2ac-4e05-8d65-9d5fab6b30d3)
   - Code 1: [Radix sort_queue](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day14/Radix_Sort_queue.c)    
     Code 2: [Radix sort_array](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day14/Radix_Sort_array.c)


