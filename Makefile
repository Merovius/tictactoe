TTT_CFLAGS += -std=c11
TTT_CFLAGS += -Wall

all: tictactoe

tictactoe: main.c tictactoe.o
	$(CC) $(TTT_CFLAGS) $(CFLAGS) -o tictactoe tictactoe.o main.c

tictactoe.o: tictactoe.c
	$(CC) $(TTT_CFLAGS) $(CFLAGS) -c -o $@ $<

test_tictactoe: test_tictactoe.c tictactoe.o
	$(CC) $(TTT_CFLAGS) $(CFLAGS) -o $@ $< tictactoe.o

test: test_tictactoe
	./test_tictactoe

clean:
	rm -f tictactoe test_tictactoe test_tictactoe.o tictactoe.o
