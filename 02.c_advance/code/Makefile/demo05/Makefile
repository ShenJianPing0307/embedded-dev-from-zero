VPATH=src1:src2:main
OBJS=f1.o f2.o main.o
CC=gcc
CLFAGS=-Wall -O -g -I include
test:${OBJS}
    ${CC} ${CLFAGS} $^ -o $@
f1.o:f1.c
    ${CC} -c $^ -o $@
f2.o:f2.c
    ${CC} -c $< -o $@
main.o:main.c
    ${CC} -c $< -o $@
.PHONY:clean
clean:
    find ./ -name "*.o" -type f -exec rm -rf \;;rm -f test