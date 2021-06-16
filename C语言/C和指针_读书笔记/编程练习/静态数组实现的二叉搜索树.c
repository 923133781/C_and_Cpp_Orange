// 使用静态数组实现二叉搜索树，长度用#define定义

#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

// 用于存储树的所有节点的数组
static TREE_TYPE tree[ARRAY_SIZE];

// left child
static int left_child(int current){
    return current*2;
}

// right child 
static int right_child(int current){
    return current*2 + 1;
}

void insert(TREE_TYPE value){
    int current;

    // 确保值为非0，因为0用提示一个未使用的节点
    assert(value!=0);

    // 从根节点开始
    current = 1;

    // 从合适的子树开始，直到到达一个叶子节点
    while(tree[current]!=0){
        // 根据情况，进入叶节点或者右子树
        if(value < tree[current])
            current = left_child(current);
        else{
            assert(value!=tree[current]);
            current = right_child(current);
        }
        assert(current<ARRAY_SIZE);
    }
    tree[current] = value;
}

// find
TREE_TYPE *find(TREE_TYPE value){
    int current;

    // 从根节点开始，直到找到那个值，进入合适的子树
    current = 1;

    while(current < ARRAY_SIZE && tree[current]!=value){
        // 根据情况，进入左子树或者右子树
        if( value < tree[current] )
            current = left_child(current);
        else
            current = right_child(current);
    }

    if(current<ARRAY_SIZE)
        return tree+current;
    else
        return 0;
}

// pre_order
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value)){
    if(current<ARRAY_SIZE && tree[current]!=0){
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value)){
    do_pre_order_traverse(1, callback);
}