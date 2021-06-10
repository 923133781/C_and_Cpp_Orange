#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

// 定义一个函数，判定一个字符是都是可打印字符
int is_not_print( int ch ){
    return !isprint(ch);    // 库函数
}

// 用于区别每种类型的分类函数的跳转表
static int(*test_func[])( int ) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,    // 检查参数c是否为标点符号或特殊符号
    is_not_print
};

#define N_CATEGORIES (sizeof(test_func)/sizeof(test_func[0]))

// 每种类型的名字
char *label[] = {
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "non-printable"
};

// 目前见到的每种类型的字符数以及字符的总量
int count[ N_CATEGORIES ];
int total;

int main(){
    int ch;
    int category;

    // 读取和处理每个字符
    while( (ch = getchar()) != EOF ){
        total += 1;

        // 为这个字符调用每个测试函数，若未真，对应计数器的值加一
        for( category = 0; category < N_CATEGORIES; category+=1){
            if( test_func[category](ch) ){
                count[ category ] += 1;
            }
        }
    }

    // 打印结果
    if( total == 0 ){
        printf("No characters in the input!\n");
    }
    else{
        for( category = 0; category < N_CATEGORIES; category+=1){
            printf("%3.0f%% %s characters\n", 
            count[category]*100.0/total,
            label[category]);
        }
    }

    return 0;
}