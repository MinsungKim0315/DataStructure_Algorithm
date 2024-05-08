#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* KeyType;
typedef char* ValueType;
typedef enum ElementStatus {
	EMPTY, OCCUPIED, DELETED
}ElementStatus;

typedef struct ElementType {
	KeyType key;
	ValueType value;
	ElementStatus status;
}ElementType;

typedef struct HashTable {
	int occupiedCount;
	int size;
	ElementType* table;
}HashTable;

HashTable* initHashTable(int TableSize); //초기화
void set(HashTable** HT, KeyType Key, ValueType Value);	//삽입
ValueType get(HashTable* HT, KeyType Key);	//검색
int erase(HashTable* HT, KeyType Key);	//삭제
void freeHashTable(HashTable* HT);	//해쉬 테이블 삭제
void clear(ElementType* Element);	//저장 공간 삭제
int HashFunction(KeyType Key, int KeyLength, int Tablesize);	//해쉬 함수
int HashFunction2(KeyType Key, int KeyLength, int Tablesize);	//인덱스 해쉬
void HashTableResize(HashTable** HT);	//해쉬 테이블 확장

int main(void) {
	HashTable* HT = initHashTable(11); // 소수

	set(&HT, "Aaron", "010-1234-5678");
	set(&HT, "Benedict", "010-4321-8765");
	set(&HT, "Charles", "010-2345-6789");
	set(&HT, "Donald", "010-5432-9876");
	set(&HT, "Edward", "010-3456-7890");
	set(&HT, "Gabriel", "010-6543-0987");
	set(&HT, "Henry", "010-4567-8901");
	set(&HT, "Issac", "010-7654-1098");
	set(&HT, "John", "010-5678-9012");
	set(&HT, "Louis", "010-8765-2109");
	set(&HT, "Michael", "010-6789-0123");
	set(&HT, "Nicholas", "010-9876-3210");
	set(&HT, "Oliver", "010-7890-1234");
	set(&HT, "Patrick", "010-0987-4321");
	set(&HT, "Philip", "010-8901-2345");
	set(&HT, "Robert", "010-1098-5432");
	set(&HT, "Samuel", "010-9012-3456");
	set(&HT, "Thomas", "010-2109-6543");
	set(&HT, "Vincent", "010-1928-3746");
	set(&HT, "William", "010-8291-6473");

	erase(HT, "Aaron");
	erase(HT, "Benedict");
	erase(HT, "Charles");

	printf(" 1. Key:%15s, Value:%15s\n", "Adam", get(HT, "Adam"));      // Nothing key, value
	printf(" 2. Key:%15s, Value:%15s\n", "Aaron", get(HT, "Aaron"));     // erase key, value
	printf(" 3. Key:%15s, Value:%15s\n", "Benedict", get(HT, "Benedict"));  // erase key, value
	printf(" 4. Key:%15s, Value:%15s\n", "Charles", get(HT, "Charles"));   // erase key, value
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
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->size = TableSize;
	HT->table = (ElementType*)calloc(TableSize, sizeof(ElementType));
	HT->occupiedCount = 0;

	return HT;
}

void set(HashTable** HT, KeyType Key, ValueType Value) {
	double Usuage = (double)(*HT)->occupiedCount / (*HT)->size;	//해쉬 테이블 밀도 계산
	if (Usuage > 0.5) HashTableResize(HT);

	int KeyLen = strlen(Key);
	int StartAddress, Address;
	StartAddress = Address = HashFunction(Key, KeyLen, (*HT)->size);
	int StepSize = HashFunction2(Key, KeyLen, (*HT)->size);

	while ((*HT)->table[Address].status != EMPTY) {	//Collision
		if ((*HT)->table[Address].status == DELETED || strcmp((*HT)->table[Address].key, Key) != 0) {	//Status is 'DELETED' OR there is already another key assigned.
			printf("Key(% 15s), Address(% 5d), StepSize(% 5d) ::Collision occured!\n", Key, Address, StepSize);
			Address = (Address + StepSize) % (*HT)->size;
			if (StartAddress == Address) {
				HashTableResize(HT);
				return set(HT, Key, Value);
			}
		}
		else return;
	}
	(*HT)->table[Address].key = (char*)malloc(sizeof(char) * (KeyLen + 1));
	strcpy_s((*HT)->table[Address].key, strlen(Key) + 1, Key);
	(*HT)->table[Address].value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
	strcpy_s((*HT)->table[Address].value, strlen(Value) + 1, Value);
	(*HT)->table[Address].status = OCCUPIED;
	(*HT)->occupiedCount++;
	printf("Key(%15s), address(%5d), %26s\n", Key, Address, ":: Entered");
}

ValueType get(HashTable* HT, KeyType Key) {
	int KeyLen = strlen(Key);
	int StartAddress, Address;
	StartAddress = Address = HashFunction(Key, KeyLen, HT->size);
	int StepSize = HashFunction2(Key, KeyLen, HT->size);
	
	while (HT->table[Address].status != EMPTY) { // DELETED or OCCUPIED
		if (HT->table[Address].key == NULL || strcmp(HT->table[Address].key, Key) != 0) {	//(HT->table[Address].key == NULL) == (HT->table[Address].status == DELETED)
			Address = (Address + StepSize) % HT->size;
			if (StartAddress == Address) return NULL;
		}
		else break; // OCCUPIED && strcmp == 0
	}
	return HT->table[Address].value;
}
int erase(HashTable* HT, KeyType Key) {
	int KeyLen = strlen(Key);
	int StartAddress, Address;
	StartAddress = Address = HashFunction(Key, KeyLen, HT->size);
	int StepSize = HashFunction2(Key, KeyLen, HT->size);
	while (HT->table[Address].status != EMPTY) { // DELETED or OCCUPIED
		if (HT->table[Address].key != NULL && strcmp(HT->table[Address].key, Key) == 0) {
			clear(&(HT->table[Address]));
			return 1;
		}
		else { // DELETED || strcmp != 0
			Address = (Address + StepSize) % HT->size;
			if (StartAddress == Address) break;
		}
	}
	return 0;
}
void clear(ElementType* Element) {
	if (Element->status == EMPTY || Element->status == DELETED) return;
	free(Element->key);
	free(Element->value);
	Element->key = NULL;
	Element->value = NULL;
	Element->status = DELETED;
}
void freeHashTable(HashTable* HT) {
	for (int i = 0; i < HT->size; i++) clear(&(HT->table[i]));
	free(HT->table);
	free(HT);
}
int HashFunction(KeyType Key, int KeyLength, int TableSize) {
	int HashValue = 0;
	for (int i = 0; i < KeyLength; i++) HashValue = (HashValue << 3) + Key[i];
	HashValue = HashValue % TableSize;
	return HashValue;
}
int HashFunction2(KeyType Key, int KeyLength, int TableSize) {
	int HashValue = 0;
	for (int i = 0; i < KeyLength; i++) HashValue = (HashValue << 2) + Key[i];
	HashValue = HashValue % (TableSize - 3);
	return HashValue + 1;
}
void HashTableResize(HashTable** HT) {
	ElementType* OldTable = (*HT)->table;
	HashTable* NewHT = initHashTable((*HT)->size * 2);
	printf("\nHashTableResize. New table size is : %5d\n\n", NewHT->size);
	for (int i = 0; i < (*HT)->size; i++)
		if (OldTable[i].status == OCCUPIED)
			set(&NewHT, OldTable[i].key, OldTable[i].value);
	freeHashTable((*HT));
	(*HT) = NewHT;
}
