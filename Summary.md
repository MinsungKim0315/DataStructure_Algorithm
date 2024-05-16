# DataStructure_Algorithm
## 2024/05/14 Complete
* * *
## 자료 구조
Linked List
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

Stack
