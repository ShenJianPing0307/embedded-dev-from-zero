OBJS=src1/f1.o src2/f2.o main/main.o
CC=gcc
CLFAGS=-Wall -O -g -I include
test:${OBJS}
    ${CC} ${CLFAGS} $^ -o $@
f1.o:src1/f1.c
    ${CC} -c $^ -o $@
f2.o:src2/f2.c
    ${CC} -c $< -o $@
main.o:main/main.c
    ${CC} -c $< -o $@
.PHONY:clean
clean:
    find ./ -name "*.o" -type f -exec rm -rf \;;rm -f test