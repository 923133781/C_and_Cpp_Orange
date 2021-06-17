// 链表实现队列

#include "queue.h"
#include <stdio.h>
#include <assert.h>

typedef struct QUEUE_NODE{
    QUEUE_TYPE value;
    struct QUEUE_NODE *next;
}QueueNode;

// 指向队列第1个和最后一个节点的指针
static QueueNode *front;
static QueueNode *rear;

// destroy_queue
void destroy_queue( void ){
    while(!is_empty())
        delete();
}

// insert
void insert(QUEUE_TYPE value){
    QueueNode *new_node;

    // 分配一个新节点，并填充各个字段
    new_node = (QueueNode *)malloc(sizeof(QueueNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = NULL;

    // 插入到队列尾部
    if(rear == NULL){
        front = new_node;
    }
    else{
        rear->next = new_node;
    }
    rear = new_node;
}

// delete
void delete(void){
    QueueNode *next_node;

    // 从队列的头部删除一个节点，如果他是最后一个节点，将rear设置为NULL
    assert( !is_empty() );
    next_node = front->next;
    free(front);
    front = next_node;
    if(front == NULL){
        rear = NULL;
    }
}

// first
QUEUE_TYPE first(void){
    assert(!is_empty() );
    return front->value;
}

// is_empty()
int is_empty(void){
    return front == NULL;
}

// is_full
int is_full(void){
    return 0;
}