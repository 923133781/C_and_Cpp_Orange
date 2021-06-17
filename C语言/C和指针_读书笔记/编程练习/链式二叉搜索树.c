// 一个使用动态分配的链式结构实现的二叉搜索树

#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

// TreeNode结构体
typedef struct TREE_NODE{
    TREE_TYPE   value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
}TreeNode;

// 指向根节点的指针
static TreeNode *tree;

// insert
void insert( TREE_TYPE value ){
    TreeNode *current;
    TreeNode **link;

    // 从根节点开始
    link = &tree;

    // 持续查找进入合适的子树
    while( (current = *link) != NULL ){
        if( value < current->value )
            link = &current->left;
        else{
            assert( value != current->value );
            link = &current->right;
        }
    }

    // 分配一个新节点，使适当节点的link指向它
    current = malloc( sizeof(TreeNode ) );
    assert( current != NULL );
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

// find
TREE_TYPE *find(TREE_TYPE value){
    TreeNode *current;
    current = tree;
    while(current!=NULL && current->value != value){
        if(value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if(current != NULL)
        return &current->value;
    else
        return NULL;
}

// do_pre_order_traverse
static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value)){
    if(current != NULL){
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value)){
    do_pre_order_traverse(tree, callback);
}