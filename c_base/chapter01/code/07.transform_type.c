#include <stdio.h>

int main(){

    int a=20, b=0;
    float c=1.23, d=2.3;
    b = (int)(a+c+d);
    printf("b=%d\n", b); //b=23
    return 0;
}