
// 一个队列的接口
#include <stdlib.h>

#define QUEUE_TYPE int  //队列元素类型

//create queue
void create_queue(size_t size);

// destroy_queue
void destroy_queue(void);

// insert
void insert( QUEUE_TYPE value );

// delete
void delete( void );

// first
QUEUE_TYPE first( void );

// is_empty
int is_empty(void);

// is_full
int is_full(void);