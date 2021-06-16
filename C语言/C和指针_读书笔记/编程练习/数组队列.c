// 一个静态数组实现队列，数组的长度只能通过修改#define定义并重新编译模块进行调整
// 使用不完全填满数组的策略区分空队列和满队列


#include "queue.h"
#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE 100 // 队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE + 1) //数组长度

// 用于存储队列元素的数字和指向队列头尾指针
static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

// insert
void insert(QUEUE_TYPE value){
    assert(!is_full());
    rear = (rear+1)%ARRAY_SIZE;
    queue[rear] = value;
}

// delete
void delete( void ){
    assert( !is_empty() );
    front = (front + 1)%ARRAY_SIZE;
}

// first
QUEUE_TYPE first( void ){
    assert(!is_empty());
    return queue[front];
}

// is_empty
int is_empty( void ){
    return (rear+1)%ARRAY_SIZE == front;
}

// is_full
int is_full(void){
    return (rear+2) % ARRAY_SIZE == front;
}