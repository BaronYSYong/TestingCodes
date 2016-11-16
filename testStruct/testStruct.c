/*!
 * @file testStruct.c
 * @brief test struct in C
 * @date 2013/11/28
 * @author Yong Yoon Seong
 * 
 * compile with 
 * prompt> gcc -ggdb3 -o testStruct testStruct.c
 * prompt> gdb ./testStruct
 * use "break" to stop at the line you want,then "run", 
 * use "print" to check the variable
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct test {
        int a;
        double b;
    } ts1, *ts2;

    ts1.a = 5;
    ts1.b = 0.1;

    ts2 = (struct test *)malloc(sizeof(struct test));
    ts2->a = 1;
    ts2->b = 0.2;

    return 0;
}
