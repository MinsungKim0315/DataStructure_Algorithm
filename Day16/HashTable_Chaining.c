#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct Node {
	KeyType key;
	ValueType value;
	struct Node* next;
}Node;

typedef Node* List;
typedef struct HashTable {
	int size;
	List* table;
}HashTable;

HashTable* initHashTable(int TableSize); // 초기화
void set(HashTable* HT, KeyType _key, ValueType _value); // 삽입
ValueType get(HashTable* HT, KeyType _key); // 검색
int erase(HashTable* HT, KeyType _key); // 삭제
void freeHashTable(HashTable* HT); // 해쉬 테이블 삭제

int HashFunction(KeyType Key, int KeyLength, int TableSize); // 해쉬 함수
Node* insertNode(List table, KeyType _key, ValueType _value);//노드 삽입
void deleteNode(Node* node); // 노드 삭제
void freeList(List node); // 해쉬 테이블 체이닝 리스트 삭제

int main(void) {
	HashTable* HT = initHashTable(11); // 소수

	set(HT, "Aaron", "010-1234-5678");
	set(HT, "Benedict", "010-4321-8765");
	set(HT, "Charles", "010-2345-6789");
	set(HT, "Donald", "010-5432-9876");
	set(HT, "Edward", "010-3456-7890");
	set(HT, "Gabriel", "010-6543-0987");
	set(HT, "Henry", "010-4567-8901");
	set(HT, "Issac", "010-7654-1098");
	set(HT, "John", "010-5678-9012");
	set(HT, "Louis", "010-8765-2109");
	set(HT, "Michael", "010-6789-0123");
	set(HT, "Nicholas", "010-9876-3210");
	set(HT, "Oliver", "010-7890-1234");
	set(HT, "Patrick", "010-0987-4321");
	set(HT, "Philip", "010-8901-2345");
	set(HT, "Robert", "010-1098-5432");
	set(HT, "Samuel", "010-9012-3456");
	set(HT, "Thomas", "010-2109-6543");
	set(HT, "Vincent", "010-1928-3746");
	set(HT, "William", "010-8291-6473");

	erase(HT, "Aaron");
	erase(HT, "Benedict");
	erase(HT, "Charles");

	printf(" 1. Key:%15s, Value:%15s\n", "Adam", get(HT, "Adam"));     // Nothing key, value
	printf(" 2. Key:%15s, Value:%15s\n", "Aaron", get(HT, "Aaron"));    // erase key, value
	printf(" 3. Key:%15s, Value:%15s\n", "Benedict", get(HT, "Benedict")); // erase key, value
	printf(" 4. Key:%15s, Value:%15s\n", "Charles", get(HT, "Charles"));  // erase key, value
	printf(" 5. Key:%15s, Value:%15s\n", "Donald", get(HT, "Donald"));
	printf(" 6. Key:%15s, Value:%15s\n", "Edward", get(HT, "Edward"));
	printf(" 7. Key:%15s, Value:%15s\n", "Gabriel", get(HT, "Gabriel"));
	printf(" 8. Key:%15s, Value:%15s\n", "Henry", get(HT, "Henry"));
	printf(" 9. Key:%15s, Value:%15s\n", "Issac", get(HT, "Issac"));
	printf("10. Key:%15s, Value:%15s\n", "John", get(HT, "John"));
	printf("11. Key:%15s, Value:%15s\n", "Louis", get(HT, "Louis"));
	printf("12. Key:%15s, Value:%15s\n", "Michael", get(HT, "Michael"));
	printf("13. Key:%15s, Value:%15s\n", "Nicholas", get(HT, "Nicholas"));
	printf("14. Key:%15s, Value:%15s\n", "Oliver", get(HT, "Oliver"));
	printf("15. Key:%15s, Value:%15s\n", "Patrick", get(HT, "Patrick"));
	printf("16. Key:%15s, Value:%15s\n", "Philip", get(HT, "Philip"));
	printf("17. Key:%15s, Value:%15s\n", "Robert", get(HT, "Robert"));
	printf("18. Key:%15s, Value:%15s\n", "Samuel", get(HT, "Samuel"));
	printf("19. Key:%15s, Value:%15s\n", "Thomas", get(HT, "Thomas"));
	printf("20. Key:%15s, Value:%15s\n", "Vincent", get(HT, "Vincent"));
	printf("21. Key:%15s, Value:%15s\n", "William", get(HT, "William"));

	freeHashTable(HT);
	return 0;
}

HashTable* initHashTable(int TableSize) {
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->size = TableSize;
	newTable->table = (List*)calloc(TableSize, sizeof(List));

	return newTable;
}
void set(HashTable* HT, KeyType Key, ValueType value) {
	int Address = HashFunction(Key, strlen(Key), HT->size);
	if (HT->table[Address] == NULL) {
		printf("Key(%15s), address(%5d) :: Entered\n", Key, Address);
	}
	else {
		printf("Key(%15s), Address(%5d) :: Collision occured!\n", Key, Address);
	}
	HT->table[Address] = insertNode(HT->table[Address], Key, value);
}

ValueType get(HashTable* HT, KeyType _Key) {
	int Address = HashFunction(_Key, strlen(_Key), HT->size);
	for (List head = HT->table[Address]; head != NULL; head = head->next) {
		if (strcmp(head->key, _Key) == 0) {
			return head->value;
		}
	}
	return 0;
}

int erase(HashTable* HT, KeyType _Key) {
	int address = HashFunction(_Key, strlen(_Key), HT->size);
	for (List head = HT->table[address], preNode = NULL; head != NULL; head = head->next) {
		if (strcmp(head->key, _Key) == 0) {
			if (preNode == NULL) HT->table[address] = head->next;  //case when first node is erased
			else preNode->next = head->next;
			deleteNode(head);
			return 1;
		}
		preNode = head;
	}
	return 0;
}

Node* insertNode(List table, KeyType _key, ValueType _value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = (char*)calloc(strlen(_key) + 1, sizeof(char));
	strcpy_s(newNode->key, strlen(_key) + 1, _key);	
	newNode->value = (char*)calloc(strlen(_value) + 1, sizeof(char));
	strcpy_s(newNode->value, strlen(_value) + 1, _value);
	newNode->next = table;

	return newNode;
}
void deleteNode(Node* node) {
	free(node->key);
	free(node->value);
	free(node);
}
int HashFunction(KeyType _Key, int KeyLength, int TableSize) {
	int HashValue = 0;
	for (int i = 0; i < KeyLength; i++) HashValue = (HashValue << 3) + _Key[i];
	HashValue = HashValue % TableSize;
	return HashValue;
}
void freeHashTable(HashTable* HT) {
	for (int i = 0; i < HT->size; i++)
		for (Node* pNode = HT->table[i], *removed = NULL; pNode != NULL;) {
			removed = pNode;
			pNode = pNode->next;
			deleteNode(removed);
		}
	free(HT->table);
	free(HT);
}
void freeList(List node) {
	if (node) {
		freeList(node->next);
		deleteNode(node);
	}
}
