#include <stdio.h>

int main(void) {

    int a ;
    int b;
    int c;

    a = b = c = 10;

    int tag = 2;

    /*switch (tag) {
        case 1: printf("Montag\n");break;
        case 2: printf("Dienstag\n");break;
        case 3: printf("Mittwoch\n");break;
        case 4: printf("Donnerstag\n");break;
        case 5:
        case 6:
        case 7:printf("Wochende\n");break;
        default: printf("Fehler\n");break;
    }*/

    for(int i = 0, n =10; i < n; i ++) {

        if(5 == i) continue;
        printf("%d\n", i);
    }


    /*while(a) {
        printf("%d\n", --a);

    }
     */
    do {
        printf("%d\n", --a);
    } while(a);

    printf("Hello, World!\n");
    return 0;
}
