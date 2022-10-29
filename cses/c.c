#include <stdio.h>
int main(void){
    int a = 10, b = 2, c;
    a = !(c = c == c) && ++b;
    printf("%d", b);
    return 0;
}