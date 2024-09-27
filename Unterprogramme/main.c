#include <stdio.h>
#include "MyIO.h"
#include "CounterModul.h"
#define X 20
void MyIO_ausgabe(); // Prototypendeclaration oder vorwärtsdeclaration

void foo() {
    for(volatile int i = 0;  i < 10; ++i){
        // mache wad mit i
    }
}





int main(void) {
   /* MyIO_ausgabe();

    MyIO_ausgabe();

    MyIO_ausgabe();
    */

   printf("%d\n", getCounter());
  
   incrementCounter();
   printf("%d\n", getCounter());



    return X;
}






