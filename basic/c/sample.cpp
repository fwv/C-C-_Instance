#include <stdio.h>
void sample_isntance();
void comma_expression();
void ifcondition();
void scanf_width();
void switch_case();
void do_while_instance();
void for_instance();
void str_instance();
void array_instance();

void sample_instance()
{
    // comma_expression();
    // ifcondition();
    // scanf_width();
    // switch_case();
    // do_while_instance();
    // for_instance();
    // str_instance();
    array_instance();
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

void switch_case() //input: H output:all  reason:miss break;1)search case 2)break 3)no match case thus go to default
{
    char ch;
    ch = getchar();
    switch (ch)
    {
    case 'H':
        printf("Hello!\n");
    case 'G':
        printf("Good morning!\n");
    default:
        printf("Bye_Bye!\n");
    }
}

void do_while_instance()
{
    int x = -1;
    do
    {
        
        printf("run it! [do while]\n"); // do while will run onece
    } while (!x);

    if (!x)
    {
        printf("run it! [if]\n");
    }

    int y = 1;
    do
    {
        printf("run!\n");
    } while (y = 3); // assignment statement return 3, true forever! rather comparative statement

    printf("%d\n", y = 2); // return 2
}

void for_instance()
{
    for (int i = 0, j = 0; i < 5; ++i, j++) // expression3 below for statement
    {
        printf("i=%2d, j=%2d\n", i, j);
    }
}

void str_instance()
{
    char str[10] = "hello"; // '\0' is space
    printf("4th is =%cend\n", str[4]);
    printf("5th is =%cend\n", str[5]);
    printf("9th is =%cend\n", str[9]);
    printf("10th is =%cend\n", str[10]);
    char e = '\0';
    printf("end is =%cend\n", e);

    char s1[5];
    // scanf("%s",s1);
    // printf("%s\n", s1);

    printf("%s\n", s1);
    for (int i = 0; i < 5; i++)
    {
        printf("%3c", s1[i]);
    }
    printf("\n");
    scanf("%c", s1);
    printf("%s\n", s1);
    for (int i = 0; i < 5; i++)
    {
        printf("%3c", s1[i]);
    }
    printf("\n");
}

void array_instance()
{
    int a[][3] = {1, 2, 3, 4, 5, 6}; // correct, maybe segment fault
    //int a[2][] = {1,2,3,4,5,6}; // wrong:an array may not have elements of this type
    //int a[2][] = {{1,2,3},{4,5,6}}; // wrong: an array may not have elements of this type

    // output:
    // 1  2  0  0
    // 1  2  3  0
    // 0  0  0  0
    // -13642300832767-1456960000512139378
    // one {} one initialization. a[][3] doesn't initialize.
    int b[][4] = {
                   {1, 2,},
                   {1, 2, 3},
                   {},
                  };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%3d", b[i][j]);
        }
        printf("\n");
    }

    // int c[100] = 0; //wrong
    int c[] = {0};
    printf("size of c is: %ld\n", sizeof(c));
        for (int j = 0; j < 40; j++)
        {
            printf("%3d", c[j]);
        }
    
    int d[100] = {0};
    int e[100][100] = {0};
    char f[100][1000][1000] = {'c'};

    char s[] = "hello";
    // s = "hello"; //wrong
    char s1[] = {"hello"};
    int g[] = {'a', 'b'};

    int h[10];
    printf("size of h is: %ld\n", sizeof(h));

}
