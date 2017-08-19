CFLAGS := -std=c99 -Wall -Werror -lncurses

CFILES := $(wildcard *.c)
OBJECTS := $(CFILES:%.c=%.o)

jumper.exe: $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $@ -lm

%.o : %.c *.h
	gcc -c $<

launch: jumper.exe
	./jumper.exe

clean:
	rm -f *.o *.exe
