#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int element;
typedef struct Heap {
    int capacity;    // 저장 가능한 원소의 최대 수량
    int size;        // 저장 할 칸 번호, size - 1 : 저장한 원소 개수
    element* ary;    // 원소를 저장하는 배열
}Heap;
Heap* heapInitialize(); // 초기화
void heapAdd(Heap* heap, element value); // 원소 추가
element heapRemove(Heap* heap); // 루트 삭제 & 반환
void heapSort(element* arr, int size); // heap 정렬
void heapFree(Heap** heap); // heap 제거
void printHeap(Heap* heap); // heap 트리 형식 출력
void arrDisplay(element* arr, int size); // 배열 출력
int main() {
    element arr[] = { 12, 15, 21, 6, 30, 3, 24, 27, 9, 18 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Heap* heap = heapInitialize();
    printf("원본 배열 : ");
    arrDisplay(arr, size);
    for (int i = 0; i < size; i++)
        heapAdd(heap, arr[i]);
    printf("heap 배열 : ");
    arrDisplay(heap->ary, heap->size);
    printHeap(heap);
    heapSort(arr, size);
    printf("sort 배열 : ");
    arrDisplay(arr, size);
    heapFree(&heap);
    return 0;
}
Heap* heapInitialize() {//heap 초기화
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) return NULL;
    heap->capacity = 2;  // capacity 멤버 초기화, 2칸 생성
    heap->size = 1;      // size 멤버 초기화, 1번 방 부터 시작
    heap->ary = (element*)calloc(heap->capacity, sizeof(element)); // ary 멤버 동적 할당
    if (heap->ary == NULL) return NULL;
    return heap;
}
void heapAdd(Heap* heap, element value) {
    if (heap->size == heap->capacity) { //꽉 차이있는 상태
        heap->capacity = heap->capacity * 2;
        element* oldarray = heap->ary;
        heap->ary = (element*)realloc(heap->ary, heap->capacity * sizeof(element));
        if (heap->ary == NULL) { free(oldarray); exit(1); }
    }
    int input = heap->size++;   //넣어야할 방 인덱스
    while (input != 1 && value > heap->ary[input / 2]/*부모노드*/) {// 부모노드와 비교 후 교환
        heap->ary[input] = heap->ary[input / 2];
        input = input / 2;
    }
    heap->ary[input] = value;
}
element heapRemove(Heap* heap) {
    if (heap->size <= 1) return 0;
    element root = heap->ary[1];
    element insert = heap->ary[--heap->size]; // 마지막 힙 원소 저장 & 원소 수 1 감소
    if (2 < heap->capacity && heap->size < heap->capacity / 2) {
        heap->capacity = heap->capacity / 2;
        element* oldarray = heap->ary;
        heap->ary = (element*)realloc(heap->ary, heap->capacity * sizeof(element));
        if (heap->ary == NULL) { free(oldarray); exit(1); }
    }
    int parent = 1, child = 2;
    while (child < heap->size) { // shift down 반복문
        if (child + 1 < heap->size && heap->ary[child] < heap->ary[child + 1]) child++; // 자식 왼쪽 & 오른쪽 비교
        if (insert >= heap->ary[child]) break; // 부모와 자식 노드 비교
        heap->ary[parent] = heap->ary[child]; //자식을 부모에 대입
        parent = child; // 기준 노드 변경 [ 부모 -> 자식 ]
        child = child * 2; // 기준 노드 변경 [ 자식 -> 손주 ]
    }
    heap->ary[parent] = insert; // 마지막 노드 최종 위치 삽입
    return root; // 루트 노드 반환
}
void heapSort(element* arr, int size) {
    Heap* heap = heapInitialize();
    for (int i = 0; i < size; i++)
        heapAdd(heap, arr[i]);
    for (int i = 0; i < size; i++)
        arr[i] = heapRemove(heap);
    heapFree(&heap);
}
void heapFree(Heap** heap) {
    free((*heap)->ary);//동적 할당 해제
    free(*heap);
    *heap = NULL; // prevent Dangling Pointer
    printf("Heap 할당 해제\n");
}
void printHeap(Heap* heap) { // 완전 이진 트리, 레벨에 따라 출력 pow(2, level)
    if (heap->size <= 1) return;
    printf("\n");
    for (int i = 1, level = 1; i < heap->size; i++) {
        printf("%3d", heap->ary[i]);
        if (i == (int)pow(2, level) - 1) {
            printf("\n");
            level++;
        }
    }
    printf("\n\n");
}
void arrDisplay(element* arr, int size) {// 배열값 출력
    for (int i = 0; i < size; i++) printf("%5d ", arr[i]);
    printf("\n");
}
