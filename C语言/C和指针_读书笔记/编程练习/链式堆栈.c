#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

// 定义一个结构体存储堆栈元素， 其中next字段指向堆栈的下一个元素
typedef struct STACK_NODE{
    STACK_TYPE value;
    struct STACK_NODE *next;
}StackNode;

//指向堆栈中第一个节点的指针
static StackNode *stack;

//create_stack
void create_stack( size_t size ){

}

// destroy stack
void destroy_stack(void){
    while(!is_empty()){
        pop();
    }
}

// push
void push( STACK_TYPE value ){
    StackNode *new_node;

    new_node = malloc(sizeof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
}

// pop
void pop(void){
    StackNode *first_node;
    assert(!is_empty());
    first_node = stack;
    stack= first_node->next;
    free(first_node);
}

// top
STACK_TYPE top(void){
    assert(!is_empty());
    return stack->value;
}

// is_empty
int is_empty(){
    return stack == NULL;
}

// is_full
int is_full(void){
    return FALSE;
}