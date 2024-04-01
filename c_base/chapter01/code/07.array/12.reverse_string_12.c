#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, char *argv[]) {

    char arr[N] = {0};

    int i, j, n, temp;

    printf("Please input a string:");

//    gets(arr);
    scanf("%s", &arr);
    n = strlen(arr);
    i = 0;
    j = n - 1;

    while(i <= j) {

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    printf("%s\n", arr);

    return 0;

}