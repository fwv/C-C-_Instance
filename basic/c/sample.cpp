#include <stdio.h>
void sample_isntance();
void comma_expression();
void ifcondition();
void scanf_width();

void sample_instance()
{
    // comma_expression();
    // ifcondition();
    scanf_width();
}

void comma_expression()
{
    int k;
    printf("%d\n", (k + 2, k = 3, k = 8)); // output:8 cuz comma expression's output derives the last expression
}

void ifcondition()
{
    if (3)
    {
        printf("bingo!\n"); //output:binggo.  0 is fasle,others is true
    }

    int a = 0;
    if (!a)
    {
        printf("bingo!\n"); //output:binggo.  0 is fasle,others is true
    }
}

void scanf_width()
{
    char a;
    scanf("%3c", &a);
    printf("%c\n", a);

    int i, j;
    scanf("%3d%2d", &i, &j);
    printf("i=%d,j=%d\n", i, j); // input:1234567 output:123 45
    
}
