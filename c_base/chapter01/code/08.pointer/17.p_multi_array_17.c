#include <stdio.h>

int main(int argc, char *argv[]) {

    char * ps[5] = {"New York city", "Beijing city", "Moscow city", "London city", "Paris city"};
    char ** pps = ps;

    int i, n;

    i = 0;
    n = sizeof(ps) / sizeof(char *);
    pps = &ps[0]; // pps = ps

    while (i < n) {

        printf("%s %s \n", ps[i],*(pps+i));
        i++;

    }

    return 0;

}
/*
New York city New York city
Beijing city Beijing city
Moscow city Moscow city
London city London city
Paris city Paris city
*/