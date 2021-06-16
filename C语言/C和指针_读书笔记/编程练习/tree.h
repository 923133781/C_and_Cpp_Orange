

// 二叉搜索树模块的接口
#define TREE_TYPE int

// insert
void insert(TREE_TYPE value);

// find
TREE_TYPE *find(TREE_TYPE value);

// 前序遍历
void pre_order_traverse(void (*callback)(TREE_TYPE value));