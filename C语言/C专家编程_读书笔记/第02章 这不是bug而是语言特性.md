### 2.1 这关于特性何事

一个`L`的`NUL`和两个`L`的`NULL`

- NUL用于结束一个ACSII字符串
- NULL用于表示空指针



### 2.2 多做之处



const不是一个真正的常量，而switch语句的case要求是一个常量。所以以下代码会编译出错。

```cpp
    const int two=2;
    switch(i)
    {
        case 1:
            printf("case 1\n");
        case two:
            printf("case two");
    }
```

**名词fall through:意思就是如果case语句后面不加break，程序就会继续执行下去**
 一个忘了的知识点，->表示的是指向结构体成员。



ANSI C的一个特性是 **相邻的字符串常量将被自动合并成一个字符串**

```C
printf("A second favorite children's book"
" is 'Thoms ths tank"
" tied a b csad asdefw valva'");
```





使一段代码第一次执行时的行为与以后执行时不同

```C
generate_initializer(char *string)
{
	static char separator = ' ';
	printf("%c %s \n", separator, string);
	separar = ',';
}
```

- 第一次执行时，首先打印一个空格，然后打印一个初始化字符
- 后续的初始化字符前面加上一个逗号



- 函数前加`static`，只能当前函数使用
- 函数前加`extern`或者不加表示  全局可见



### 2.3 误做之过



**C语言中的符号重载**

|  符号  | 意义                                                         |
| :----: | :----------------------------------------------------------- |
| static | 在函数内部，表示该变量的值在各个调用间一直保持延续性在函数这一级，<br>表示该函数只对本文件可见 |
| extern |                                                              |
|  void  |                                                              |
|   *    |                                                              |
|   &    |                                                              |
|   =    |                                                              |
|   ==   |                                                              |
|   <=   |                                                              |
|  <<=   |                                                              |
|   <    |                                                              |
|   ()   |                                                              |



