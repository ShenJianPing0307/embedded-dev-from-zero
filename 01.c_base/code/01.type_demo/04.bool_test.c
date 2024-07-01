#include <stdio.h>
#include <stdbool.h> //bool类型需要引入的头文件

// bool 非零为真，零为假
int main() {

    bool a;
    a = true;

    if(a) {
      printf("true %d\n", a);
    } else {
      printf("false %d\n", a);
    }

}