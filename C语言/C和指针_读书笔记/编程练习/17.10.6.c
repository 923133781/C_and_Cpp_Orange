// 层序遍历

void breadth_first_traversal( void (*callback)(TREE_TYPE value)){
    int current;
    int child;

    // 根节点插入到队列中
    queue_insert(1);

    //队列非空时
    while(!is_queue_empty()){
        // 从队列中取出第1个值进行处理
        current = queue_first();
        queue_delete();
        callback(tree[current]);

        // 将该节点的孩子加入到队列中
        child = left_child(current);
        if(child<ARRAY_SIZE && tree[child]!=0)
            queue_insert(child);
        child = right_child(current);
        if(child < ARRAY_SIZE && tree[child]!=0)
            queue_insert(child);
    }
}