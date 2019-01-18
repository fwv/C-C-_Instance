#include<iostream>
using namespace std;

 void io_instance() {
     /* majority usages about printf */
        float f = 3.141592653;
        //  printf("%f\n",f);
        //  printf("%.3f\n",f);

        int i = 1,i1,i2,i3;
        //  printf("%d\n",i);
        //  printf("%5d\n",i);
        //  printf("%05d\n",i);
        // scanf("%d-%d-%d",&i1, &i2, &i3);
        // printf("%d-%d-%d\n",i1, i2, i3);

     /* majority usages about scanf */
        double d;
        //  printf("please input d's value:");
        //  scanf("%lf",&d);
        //  printf("%lf\n",d);

    /* scanf recognizes blank and enter as string end mark. input:hello world output:hello */
        char str[5];
        int k;
        //  scanf("%s",str); 
        //  printf("the string which you have inputed is: %s\n",str);
    /* basic usage of sscanf and sprint. */
        //  sscanf(str, "%d", &k);
        //  sprintf(str, "%d", k);
        //  printf("sprintf:the interger's value transformed form the string you input is: %d\n", k);

    /* gets only recogniczes enter as string end mark. */
        //  gets(str);
        //  puts(str);

        /* char[] make '\0' as end mark,gets() will add it automatically for fear create garbled at the end of string when user input value and getchar() won't. */
        // for(int j=0;j<3;j++){
        //     str[j] = getchar();
        // }
        // str[3]=0;//add end mark at the end of string manually.'\0''s ASCII value is 0.
        // puts(str);


        int j;
        // cin >> j;
        // cout << j << "\n";
    
    /* cin recognizes bland and enter as input end mark, you are expected to use cin.getline() to input a string contains blank. */
        // cin >> str;
        // cout << str << "\n";
        // cin.getline(str,30);
        // cout << str << "\n";

 } 