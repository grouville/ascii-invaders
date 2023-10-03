# CC=gcc
CFLAGS+=-Wall
LIBS=-lncursesw -lyaml

all:	ascii_invaders

clean:
	rm -f ascii_invaders

ascii_invaders:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o ascii_invaders main.c