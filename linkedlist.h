#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct Data {
    int number;
    struct Data* next;
}Data;

typedef struct _LinkedList {
    struct Data* head;          // 처음 노드
    struct Data* tail;          // 마지막 노드
    struct Data* current;       // 현재 가리키고 있는 노드
}LinkedList;


// head, tail, current 노드를 생성 및 초기화
_Bool createList(LinkedList* linkedlist);

// 동적 할당한 모든 노드의 메모리를 반환
_Bool deleteList(LinkedList* linkedlist);

// 노드 추가
_Bool addNode(LinkedList* linkedlist, int number);

// 노드 제거
_Bool removeNode(LinkedList* linkedlist, int number);

// 노드 탐색
LinkedList* searchNode(LinkedList* linkedlist, int number);
#endif