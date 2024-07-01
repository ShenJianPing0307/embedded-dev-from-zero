#include <stdio.h>

int main() {

    float x=10.5, y=1.8, z=0;

    z = (x+=5,y=x+0.2);
    printf("z=%f\n", z); // z=15.700000

    z = (x=y=5, x+=1);
    printf("z=%f\n", z); // 6.000000

    z = (x=5, y=6, x+y);
    printf("z=%f\n", z); // z=11.000000

    z = (z=8, x=5, y=3);
    printf("z=%f\n", z); // z=3.000000

    return 0;

}