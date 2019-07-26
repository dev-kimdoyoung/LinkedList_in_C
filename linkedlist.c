#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "linkedlist.h"

int main() {
    LinkedList* linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
    createList(linkedlist);
    addNode(linkedlist, 3);
    addNode(linkedlist, 4);
    addNode(linkedlist, 5);
    addNode(linkedlist, 6);
    addNode(linkedlist, 7);
    addNode(linkedlist, 8);
    addNode(linkedlist, 9);
    deleteList(linkedlist);
    
    return 0;
}

// head, tail, current 노드를 생성 및 초기화
_Bool createList(LinkedList* linkedlist) {
    linkedlist->head = (struct Data*)malloc(sizeof(Data));
    linkedlist->tail = (struct Data*)malloc(sizeof(Data));
    linkedlist->current = linkedlist->head;
    printf("메모리 할당 성공\n");
    return TRUE;
}

// 동적 할당한 메모리 반환
_Bool deleteList(LinkedList* linkedlist) {
    // 현재 가리키고 있는 노드 위치 초기화
    linkedlist->current = linkedlist->head;
    struct Data* node = (struct Data*)malloc(sizeof(Data));

    // 만약 node가 메모리 할당에 실패하면
    if(node == NULL) {
        printf("node에 메모리 할당 실패\n");
        return FALSE;
    }

    // node에 head가 가리키는 노드를 저장
    node = linkedlist->current;

    printf("연결 노드 반환 중");
    // 현재 노드가 NULL이 아니라면(마지막 노드가 아니라면)
    while(linkedlist->current != NULL) {
        // node에 현재 노드가 가리키는 노드 저장
        node = linkedlist->current->next;

        // 데이터가 저장되어 있는 노드 메모리 반환
        memset(linkedlist->current, 0xFF, sizeof(linkedlist->current));
        free(linkedlist->current);
        linkedlist->current = node;
        printf(".");
    }
    printf("\n");
    linkedlist->current = NULL;
    printf("연결 노드 메모리 반환 완료\n");

    memset(linkedlist, 0xFF, sizeof(LinkedList));
    free(linkedlist);
    linkedlist = NULL;

    printf("linkedlist 동적 메모리 반환 완료\n");

    return TRUE;
}

// 노드 추가
_Bool addNode(LinkedList* linkedlist, int number) {
    // current가 가리키는 노드 위치 초기화
    linkedlist->current = linkedlist->head;

    // 새로 할당할 노드 동적 할당    
    struct Data* newNode = (struct Data*)malloc(sizeof(Data));

    // 입력받은 데이터를 새로운 노드의 데이터에 대입
    newNode->number = number;

    // 만약 head의 next가 가리키는 노드가 없다면
    if(linkedlist->head->next == NULL) {
        // head 다음 노드로 newNode를 가리키게 하기
        linkedlist->head->next = newNode;
        // newNode의 다음 노드는 tail(마지막) 노드
        newNode->next = linkedlist->tail;
        // 마지막 노드 다음은 NULL
        linkedlist->tail->next = NULL;
        printf("새로운 노드 연결 완료\n");
    }
    // 1개 이상의 기존 데이터 노드가 존재한다면
    else {
        // 현재 노드의 next가 tail을 가리키기 전까지 반복
        while(linkedlist->current->next != NULL) {
            linkedlist->current = linkedlist->current->next;
        }

        // 새로운 노드의 next가 마지막 노드를 가리키게 하기
        newNode->next = linkedlist->current->next;
        // 기존에 tail을 가리키던 노드가 newNode를 가리키게 하기
        linkedlist->current->next = newNode;
    }
    printf("새로운 노드 연결 완료\n");
    return TRUE;
}

// 노드 제거
_Bool removeNode(LinkedList* linkedlist, int number);

// 노드 탐색
LinkedList* searchNode(LinkedList* linkedlist, int number);