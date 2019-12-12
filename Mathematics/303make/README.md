# 303make

An algorithm that displays the adjacency matrix of a Makefile.

### Usage
```bash
./303make Makefile

    Makefile: a Makefile
```

### Output
```bash
>>> cat Makefile
tty: tty.o fc.o
cc -o tty tty.o fc.o

tty.o: tty.c fc.h
cc -c tty.c

fc.o: fc.c fc.h
cc -c fc.c

./303make Makefile
```
