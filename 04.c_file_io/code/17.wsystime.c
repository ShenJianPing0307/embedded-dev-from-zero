#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    FILE *fp;
    time_t ctime;
    struct tm *ctimestr;
    int linecount;
    char buf[32];

    if((fp=fopen("test.txt", "a+")) == NULL) {

        perror("fopen");
        return 0;

    }

    while(fgets(buf, 32, fp) != NULL) {

        if(buf[strlen(buf)-1] == '\n') {
            linecount++;
        }

    }

    while(1) {
        ctime = time(NULL);
        ctimestr = localtime(&ctime);
        fprintf(fp, "%d, %04d-%02d-%02d %02d:%02d:%02d\n", linecount,
        ctimestr->tm_year+1900, ctimestr->tm_mon+1, ctimestr->tm_mday,
        ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
        fflush(fp);
        linecount++;
        sleep(1);

    }

    fclose(fp);

}