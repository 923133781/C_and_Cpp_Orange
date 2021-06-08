#include <stdio.h>
#include <malloc.h>

#define DELTA 100

int *readints(){
    int *array;
    int size;
    int count;
    int value;

    // 获得最初的数组，大小以容纳DELTA个数
    size = DELTA;
    array = malloc( (size + 1 ) * sizeof(int) );
    if(array == NULL){
        return NULL;
    }

    // 从标准输入
    count = 0;
    while( scanf("%d", &value) == 1){
        // 若需要，变大数组
        count += 1;
        if(count > size){
            size += DELTA;
            array = realloc(array, (size+1)*sizeof(int));
            if(array == NULL){
                return NULL;
            }
        }
        array[count] = value;
    }

    if(count < size){
        array = realloc(array, (count+1)*sizeof(int));
        if(array == NULL){
            return NULL;
        }
    }
    array[0] = count;
    return array;
}

