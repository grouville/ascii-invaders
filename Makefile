#CC=gcc
CFLAGS+=-Wall
LIBS=-lncursesw -lyaml

all:	ascii_invaders

clean:
	rm -f invaders.o ascii_invaders

ascii_invaders: invaders.o
	$(CC) $(CFLAGS) $(LDFLAGS) invaders.o $(LIBS) -o ascii_invaders
