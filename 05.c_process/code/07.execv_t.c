#include <stdio.h>
#include <unistd.h>

int main(void) {

    char *argv[] = {"ls", "-a", "-l", "./", NULL};

//    if(execv("/bin/ls", argv) < 0) {
//        perror("execv");
//    }
      if(execvp("ls", argv) < 0) {
        perror("execv");
    }

}