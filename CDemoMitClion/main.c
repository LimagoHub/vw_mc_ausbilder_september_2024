#include <stdio.h>
void print_char(char herbert) {
    printf("%c", herbert);
}

void print_string(char * kommode ){
    int i = 0;
    while(kommode[i]) {
        print_char(kommode[i++]);

    }
}



int main(void) {

    int a = 10;
    char wort[] = "Hallo";


    /*
    wort[0] = 'H';
    wort[1] = 'a';
    wort[2] = 'l';
    wort[3] = 'l';
    wort[4] = 'o';
    wort[5] = 0;
*/
    //printf("%d\n", wort[0]);

    //for(int i = 0; i < 5; i++)
    //    print_char(wort[i]);

    double x = 453.144556536756746767878578542563567;

    printf("Wert = #%20.2lf# \n", x);
    printf("Wert = #%-20s# \n", "Hallo Welt");
    printf("Wert = #%20s# \n", "Hallo Welt");
    printf("Wert = #%20d# \n", 4711);

    char feld[28];
    sprintf(feld,"Wert = #%20d# \n", 4711);

    //print_string(wort);
    return 0;
}
