// 返回一个1-6的值，模拟一个六边的骰子

#include <stdlib.h>
#include <stdio.h>

// 计算将产生6作为骰子值的随机数生成函数所返回的最大数
#define MAX_OK_RAND (int)( ( ( (long)RAND_MAX + 1 ) / 6 ) * 6 - 1 )

int throw_die(void){
    static int is_seeded = 0;
    int value;

    if( !is_seeded ){
        is_seeded = 1;
        srand( (unsigned int)time( NULL ));
    }

    do{
        value = rand();
    }while(value > MAX_OK_RAND);

    return value % 6 + 1;
}