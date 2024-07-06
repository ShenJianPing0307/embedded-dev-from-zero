OBJS=f1.o f2.o main.o
CC=gcc
CLFAGS=-Wall -O -g
test:${OBJS}
    gcc ${CLFAGS} ${OBJS} -o $@
f1.o:f1.c
    gcc -c $^ -o $@
f2.o:f2.c
    gcc -c $< -o $@
main.o:main.c
    gcc -c $< -o $@
.PHONY:clean
clean:
    rm -rf *.o test