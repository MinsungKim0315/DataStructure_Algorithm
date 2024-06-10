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
* * *
## 탐색
### Linear Search
* 처음부터 끝까지 하나씩 순서대로 비교하며 원하는 값을 찾는 알고리즘
* 정렬이 필요 없다
* Code: [Linear Search](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day15/Linear_Search.c)
### Binary Search
* 반으로 나누어서 연산
* 정렬이 필요하다
* Code: [Binary Search](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day15/Binary_Search.c)
### Interpolation Search
* 정렬된 데이터 집합이 칸마다 값이 균등한 위치를 가정
* key 값의 크기로 존재할 위치를 계산해 탐색하는 방법
* $POS(k) = (high - low) * (key - array[low]) / (array[high] - array[low])$
* Code: [Interpolation Search](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day15/Interpolation_Search.c)
### Indexed Sequential Search
* 정렬된 주 자료 집합에서 일정 간격으로 발췌한 인덱스 테이블 활용한 탐색
* Code: [Indexed Sequential Search](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day15/IndexedSequential_Search.c)
* * *
## Hash
* Hashing: 키에 대한 연산으로 주소를 계산, 테이블의 자료 접근
* Hash Function: 탐색 키를 입력받아 주소를 생성
  1. 나눗셈법(제산 함수): ℎ(𝑘)=𝑘 𝑚𝑜𝑑(%)𝑚 [m = prime number]
  2. 제곱법: ℎ(𝑘)=𝑘^2÷10^𝑛𝑚𝑜𝑑(%)10^𝑚 (m>n)
  3. 기수변환법
  4. 폴딩 함수
* Hash Table: 값을 저장하기 위한 표
  ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/edfe0001-c8c7-4349-9bf5-0bf6ad3d3d3f)
  * Collision: 서로 다른 탐색 키가 같은 해쉬 주소를 가지는 현상
  * Synonym: 충돌로 같은 주소를 갖는 키의 집합
  * Overflow: 충돌로 주소에 저장할 공간이 부족해진 경우
* Hash Address: 해쉬 테이블의 인덱스
### Hash_Linear Probing
* 충돌 해결책: Linear Probing
  1. Open Addressing: 충돌 발생 시 다음 주소부터 비어 있는 주소에 저장
     * while(isOccupy()) { address = ( address + 1 ) % TableSize; }
     * HF1(key), HF1(key)+1, HF1(key)+2, ...
  2. Quadratic Probing: 충돌 발생 시 비어있는 주소 찾기위해 제곱수의 합 계산
     * while(isOccupy()) { address = ( address + i * i ) % TableSize; }
     * HF1(key), HF1(key)+1, HF1(key)+4, HF1(key)+9, ...
  3. Double Hashing = Rehashing: 비어있는 주소 찾기위해 또 다른 해쉬 함수 사용
     * while(isOccupy()) { address = ( address + HF2(key) ) % TableSize; }
 * Code: [Open Addressing](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day16/HashTable_OpenAddressing.c)
### Hash_Chaining
 * 충돌 해결책: Chaining
   * 충돌이 일어난 주소를 연결 리스트와 이진 검색 트리 구현
   * 연결 리스트와 이진 검색 트리로 충돌 및 오버플로우 문제 모두 해결
     ![image](https://github.com/MinsungKim0315/DataStructure_Algorithm/assets/88697052/01c18e5c-a7ee-48d2-b3b1-f6a19f64474a)
 * Code: [Chaining](https://github.com/MinsungKim0315/DataStructure_Algorithm/blob/main/Day16/HashTable_Chaining.c)
* * *
## Tree
